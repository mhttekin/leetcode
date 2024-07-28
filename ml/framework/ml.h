#ifndef ML_H_
#define ML_H_

#include <stddef.h>
#include <stdio.h>
#include <math.h>

#ifndef ML_ASSERT
#include <assert.h>
#define ML_ASSERT assert
#endif // ML_ASSERT

#ifndef ML_MALLOC
#include <stdlib.h>
#define ML_MALLOC malloc
#endif // ML_MALLOC


#define ARRAY_LEN(xs) (sizeof(xs))/(sizeof(xs[0])) // Macro for Array length

float rand_float(void); // Random value generator
float sigmoidf(float x); // Activation function

typedef struct {
  size_t rows;
  size_t cols;
  size_t stride;
  float *es;
} Mat; // Matrix Structure

#define MAT_AT(m, i, j) (m).es[(i)*(m).stride + (j)] // Returns the float in the desired location of the Matrix

Mat mat_alloc(size_t rows, size_t cols); // Allocates desired row and col fir a matrix
void mat_rand(Mat m, float low, float high); // Gives random values to a Matrix
Mat mat_row(Mat m, size_t row); // Takes the row of a Matrix
void mat_copy(Mat dst, Mat src); // Copies a Matrix to Another
void mat_dot(Mat dst, Mat a, Mat b); // Matrix Multiplication
void mat_sig(Mat m); // Activation function of a Matrix
void mat_sum(Mat dst, Mat a); // Sums two Matrices
void mat_fill(Mat m, float x); // Fills Matrix with float x
void mat_print(Mat m, const char *name, size_t padding); // Prints Matrix


#define MAT_PRINT(m) mat_print(m, #m, 0) // Macro for print function

typedef struct {
  size_t count;
  Mat *ws; // Weights
  Mat *bs; // Biases
  Mat *as; // Activations and Input
}NN; // Neural Network

NN nn_alloc(size_t *arch, size_t arch_count); // Neural Network Initializition
void nn_print(NN nn, const char *name); // Prints NN
void nn_rand(NN nn, float low, float high); // Randomizes matrices of NN
void nn_forward(NN nn); // Forward Propagation of Neural Network
float nn_cost(NN nn, Mat ti, Mat to); // Neural Network Cost Function
void nn_finite_diff(NN nn, NN g, float eps, Mat ti, Mat to); // Forward Finite Difference
void nn_backprop(NN nn, NN g, Mat ti, Mat to); //Backpropagation of Neural Network
void nn_learn(NN n, NN g, float rate); // Substracts the values with the gradient

#define NN_PRINT(nn) nn_print(nn, #nn) // Macro for print function
#define NN_INPUT(nn) (nn).as[0] // NN Input
#define NN_OUTPUT(nn) (nn).as[nn.count] // NN Output 

#endif //ML_H_

#ifdef ML_IMPLEMENTATION

float rand_float(void)
{
  return (float) rand() / (float) RAND_MAX;
}

float sigmoidf(float x)
{
  return 1.f / (1.f + expf(-x));
}

Mat mat_alloc(size_t rows, size_t cols)
{
  Mat m;
  m.rows = rows;
  m.cols = cols;
  m.stride = cols;
  m.es = ML_MALLOC(sizeof(*m.es)*rows*cols);
  ML_ASSERT(m.es != NULL);
  return m;
}

void mat_dot(Mat dst, Mat a, Mat b)
{
  ML_ASSERT(a.cols == b.rows);
  ML_ASSERT(dst.rows == a.rows);
  ML_ASSERT(dst.cols == b.cols);
  size_t n = a.cols;

  for(size_t i = 0; i < dst.rows; ++i)
  {
    for(size_t j = 0; j < dst.cols; ++j)
    {
      MAT_AT(dst, i, j) = 0;
      for(size_t k = 0; k < n; ++k)
      {
        MAT_AT(dst,i,j) += (MAT_AT(a,i,k) * MAT_AT(b,k,j));
      }
    }
  }
}

Mat mat_row(Mat m, size_t row)
{
  return (Mat){
    .rows = 1,
    .cols = m.cols,
    .stride = m.stride,
    .es = &MAT_AT(m, row, 0),
  };
}

void mat_copy(Mat dst, Mat src)
{
  ML_ASSERT(dst.rows == src.rows);
  ML_ASSERT(dst.cols == src.cols);
  for(size_t i = 0; i < dst.rows; ++i)
  {
    for(size_t j = 0; j < dst.cols; ++j)
    {
      MAT_AT(dst, i, j) = MAT_AT(src, i, j);
    }
  }
}

void mat_sum(Mat dst, Mat a)
{
  ML_ASSERT(dst.rows == a.rows);
  ML_ASSERT(dst.cols == a.cols);
  for(size_t i = 0; i < dst.rows; ++i)
  {
    for(size_t j = 0; j < dst.cols; ++j)
    {
      MAT_AT(dst, i, j) += MAT_AT(a, i, j);
    }  
  }
}

void mat_sig(Mat m)
{
  for(size_t i = 0; i < m.rows; ++i)
  {
    for(size_t j = 0; j < m.cols; ++j)
    {
      MAT_AT(m, i, j) = sigmoidf(MAT_AT(m, i, j));
    }
  }
}

void mat_print(Mat m, const char *name, size_t padding)
{
  printf("%*s%s = \n", (int) padding, "", name);
  for(size_t i = 0; i < m.rows; ++i)
  {
    for(size_t j = 0; j < m.cols; ++j)
    {
      printf("%*s%f ", (int) padding, "", MAT_AT(m,i,j));
    }
    printf("\n");
  }
  printf("%*s]\n", (int) padding, "");
}

void mat_fill(Mat m, float x)
{
  for(size_t i = 0; i < m.rows; ++i)
  {
    for(size_t j = 0; j < m.cols; ++j)
    {
      MAT_AT(m, i, j) = x;
    }
  }
}

void mat_rand(Mat m, float low, float high)
{
  for(size_t i = 0; i < m.rows; ++i)
  {
    for(size_t j = 0; j < m.cols; ++j)
    {
      MAT_AT(m, i, j) = rand_float()*(high - low) + low;
    }
  }
}

NN nn_alloc(size_t *arch, size_t arch_count)
{
  ML_ASSERT(arch_count > 0);

  NN nn;
  nn.count = arch_count - 1;
  nn.ws = ML_MALLOC(sizeof(*nn.ws)*nn.count);
  ML_ASSERT(nn.ws != NULL);
  nn.bs = ML_MALLOC(sizeof(*nn.bs)*nn.count);
  ML_ASSERT(nn.bs != NULL);
  nn.as = ML_MALLOC(sizeof(*nn.as)*(nn.count + 1));
  ML_ASSERT(nn.as != NULL);

  nn.as[0] = mat_alloc(1, arch[0]);
  for(size_t i = 0; i < nn.count; ++i)
  {
    nn.ws[i] = mat_alloc(arch[i], arch[i+1]);
    nn.bs[i] = mat_alloc(1, arch[i+1]);
    nn.as[i+1] = mat_alloc(1, arch[i+1]);
  }
  return nn;
}
void nn_print(NN nn, const char *name)
{
  char buf[256];
  
  printf("%s = [\n", name);
  for(size_t i = 0; i < nn.count; ++i)
  {
    snprintf(buf, sizeof(buf), "as%zu", i);
    mat_print(nn.as[i], buf, 4);
    snprintf(buf, sizeof(buf), "ws%zu", i);
    mat_print(nn.ws[i], buf, 4);
    snprintf(buf, sizeof(buf), "bs%zu", i);
    mat_print(nn.bs[i], buf, 4);
  }
}
void nn_rand(NN nn, float low, float high)
{
  for(size_t i = 0; i < nn.count; ++i)
  {
    mat_rand(nn.ws[i], low, high);
    mat_rand(nn.bs[i], low, high);
  }
}
void nn_forward(NN nn) 
{
  for (size_t i = 0; i < nn.count; ++i)
  {
    mat_dot(nn.as[i+1],nn.as[i], nn.ws[i]); 
    mat_sum(nn.as[i+1], nn.bs[i]); 
    mat_sig(nn.as[i+1]);  
  }
}
float cost(NN nn, Mat ti, Mat to)
{
  ML_ASSERT(ti.rows == to.rows);
  ML_ASSERT(to.cols == NN_OUTPUT(nn).cols);
  size_t n = ti.rows;
  float c = 0;

  for(size_t i = 0; i < n; ++i)
  {
    Mat x = mat_row(ti, i);
    Mat y = mat_row(to, i);
    mat_copy(NN_INPUT(nn), x);
    nn_forward(nn);
    
    size_t q = to.cols;
    for(size_t j = 0; j < q; ++j)
    {
      float d = MAT_AT(NN_OUTPUT(nn), 0, j) - MAT_AT(y, 0, j);
      c += d*d;
    }
  }
  return (float) c/n;
}
void nn_finite_diff(NN nn, NN g, float eps, Mat ti, Mat to)
{

  float saved = 0.f;
  float c = cost(nn, ti, to);
  for(size_t i = 0; i < nn.count; ++i)
  {
    for(size_t j = 0; j < nn.ws[i].rows; ++j)
    {
      for(size_t k = 0; k < nn.ws[i].cols; ++k)
      {
        saved = MAT_AT(nn.ws[i], j, k);
        MAT_AT(nn.ws[i], j, k) += eps;
        MAT_AT(g.ws[i], j, k) = (cost(nn, ti, to) - c) / eps;
        MAT_AT(nn.ws[i], j, k) = saved;
      }
    }
    for(size_t j = 0; j < nn.bs[i].rows; ++j)
    {
      for(size_t k = 0; k < nn.bs[i].cols; ++k)
      {
        saved = MAT_AT(nn.bs[i], j, k);
        MAT_AT(nn.bs[i], j, k) += eps;
        MAT_AT(g.bs[i], j, k) = (cost(nn, ti, to) - c) / eps;
        MAT_AT(nn.bs[i], j, k) = saved;
      }
    }  
  }
}
void nn_backprop(NN nn, NN g, Mat ti, Mat to)
{
   NN_ASSERT(ti.rows == to.rows);
   NN_ASSERT(to.cols == NN_OUTPUT(nn).cols);
   size_t n = ti.rows;

   for(size_t i = 0; i < n; ++i)
   {
     mat_copy(NN_INPUT(nn), mat_row(ti, i));
     nn_forward(nn);
     for (size_t j = 0; j < to.cols; ++j)
     {
       float y = MAT_AT(NN_OUTPUT(nn), 0, j) - MAT_AT(to, i, j);

     }
   }
  
}
void nn_learn(NN nn, NN g, float rate)
{
  for(size_t i = 0; i < nn.count; ++i)
  {
    for(size_t j = 0; j < nn.ws[i].rows; ++j)
    {
      for(size_t k = 0; k < nn.ws[i].cols; ++k)
      {
        MAT_AT(nn.ws[i], j, k) -= MAT_AT(g.ws[i], j, k)*rate;
      }
    }
    for(size_t j = 0; j < nn.bs[i].rows; ++j)
    {
      for(size_t k = 0; k < nn.bs[i].cols; ++k)
      {
        MAT_AT(nn.bs[i], j, k) -= MAT_AT(g.bs[i], j, k)*rate;
      }
    }  
  }
}

#endif  // ML_IMPLEMENTATION
