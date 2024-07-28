#define ML_IMPLEMENTATION
#include "ml.h"
#include <time.h>

//typedef struct {
//  Mat a0, a1, a2; // Input Values and Calculated Results 
//  Mat w1, b1; // First Layer W/B
//  Mat w2, b2;  // Second Layer W/B
//}Xor;
//
//Xor xor_alloc(void)
//{
//  Xor m;
//  m.a0 = mat_alloc(1, 2);
//
//  m.w1 = mat_alloc(2, 2);
//  m.b1 = mat_alloc(1, 2);
//  m.a1 = mat_alloc(1, 2);
//  m.w2 = mat_alloc(2, 1);
//
//  m.b2 = mat_alloc(1, 1);
//  m.a2 = mat_alloc(1, 1);
//  return m;
//}
//
//
//void forward_xor(Xor m) {
//
//  mat_dot(m.a1, m.a0, m.w1); 
//  mat_sum(m.a1, m.b1); 
//  mat_sig(m.a1); 
//  
//  mat_dot(m.a2, m.a1, m.w2); // Dot Product of a1 and w2
//  mat_sum(m.a2, m.b2); // Bias Addition
//  mat_sig(m.a2); // Activation Function
//}

//float cost(Xor m, Mat ti, Mat to) // Cost Function to Calculate Actual Value
//{
//  ML_ASSERT(ti.rows == to.rows);
//  ML_ASSERT(to.cols == m.a2.cols);
//  size_t n = ti.rows;
//  float c = 0.f;
//  for(size_t i = 0; i < n; ++i)
//  {
//    Mat x = mat_row(ti, i);
//    Mat y = mat_row(to, i);
//    mat_copy(m.a0, x);
//    forward_xor(m);
//
//    size_t q = to.cols;
//    for(size_t j = 0; j < q; ++j)
//    {
//      float d = MAT_AT(m.a2, 0, j) - MAT_AT(y, 0, j);
//      c += d*d;
//    }
//  }
//  return (float) c/n;
//}

//void finite_diff(Xor m, Xor g, float eps, Mat ti, Mat to)
//{
//  float saved = 0.f;
//  float c = cost(m, ti, to);
//  for(size_t i = 0; i < m.w1.rows; ++i)
//  {
//    for(size_t j = 0; j < m.w1.cols; ++j)
//    {
//      saved = MAT_AT(m.w1, i, j);
//      MAT_AT(m.w1, i, j) += eps;
//      MAT_AT(g.w1, i, j) = (cost(m, ti, to) - c) / eps;
//      MAT_AT(m.w1, i, j) = saved;
//    }
//  }
//  for(size_t i = 0; i < m.b1.rows; ++i)
//  {
//    for(size_t j = 0; j < m.b1.cols; ++j)
//    {
//      saved = MAT_AT(m.b1, i, j);
//      MAT_AT(m.b1, i, j) += eps;
//      MAT_AT(g.b1, i, j) = (cost(m, ti, to) - c) / eps;
//      MAT_AT(m.b1, i, j) = saved;
//    }
//  }
//  for(size_t i = 0; i < m.w2.rows; ++i)
//  {
//    for(size_t j = 0; j < m.w2.cols; ++j)
//    {
//      saved = MAT_AT(m.w2, i, j);
//      MAT_AT(m.w2, i, j) += eps;
//      MAT_AT(g.w2, i, j) = (cost(m, ti, to) - c) / eps;
//      MAT_AT(m.w2, i, j) = saved;
//    }
//  }
//  for(size_t i = 0; i < m.b2.rows; ++i)
//  {
//    for(size_t j = 0; j < m.b2.cols; ++j)
//    {
//      saved = MAT_AT(m.b2, i, j);
//      MAT_AT(m.b2, i, j) += eps;
//      MAT_AT(g.b2, i, j) = (cost(m, ti, to) - c) / eps;
//      MAT_AT(m.b2, i, j) = saved;
//    }
//  }
//}
//void learn(Xor m, Xor g, float rate) 
//{
//  for(size_t i = 0; i < m.w1.rows; ++i)
//  {
//    for(size_t j = 0; j < m.w1.cols; ++j)
//    {
//      MAT_AT(m.w1, i, j) -= MAT_AT(g.w1, i, j)*rate;
//    }
//  }
//  for(size_t i = 0; i < m.b1.rows; ++i)
//  {
//    for(size_t j = 0; j < m.b1.cols; ++j)
//    {
//      MAT_AT(m.b1, i, j) -= MAT_AT(g.b1, i, j)*rate;
//    }
//  }
//  for(size_t i = 0; i < m.w2.rows; ++i)
//  {
//    for(size_t j = 0; j < m.w2.cols; ++j)
//    {
//      MAT_AT(m.w2, i, j) -=  MAT_AT(g.w2, i, j)*rate;
//    }
//  }
//  for(size_t i = 0; i < m.b2.rows; ++i)
//  {
//    for(size_t j = 0; j < m.b2.cols; ++j)
//    {
//      MAT_AT(m.b2, i, j) -= MAT_AT(g.b2, i, j)*rate;
//    }
//  }
//}
float td_xor[] = {
  0, 0, 0,
  0, 1, 1,
  1, 0, 1,
  1, 1, 0,
};
float td_sum[] = {
  0, 0,  0, 0,  0, 0,
  0, 0,  0, 1,  0, 1,
  0, 1,  0, 1,  1, 0,
  0, 1,  1, 0,  1, 1
};

int main(void)
{
  float *td = td_xor;   
  size_t n = 4;
  size_t stride = 3;
  
  Mat ti = {
    .rows = n,
    .cols = 2,
    .stride = stride,
    .es = td
  };

Mat to = {
    .rows = n,
    .cols = 1,
    .stride = stride,
    .es = td + 2
  };
  srand(time(NULL));
  size_t arch[] = {2,2,1};
  NN nn = nn_alloc(arch, ARRAY_LEN(arch));
  NN gg = nn_alloc(arch, ARRAY_LEN(arch));
  nn_rand(nn, 0, 1);

  float eps = 1e-1; 
  float rate = 1e-1;
  for(size_t i = 0; i < 500*1000; ++i)
  {
    nn_finite_diff(nn, gg, eps, ti, to);
    nn_learn(nn, gg, rate);
  }
  printf("%f\n", cost(nn, ti, to));
  for(size_t i = 0; i < 2; ++i) {
    for(size_t j = 0; j < 2; ++j){
      MAT_AT(NN_INPUT(nn), 0, 0) = i;
      MAT_AT(NN_INPUT(nn), 0, 1) = j;
      //mat_copy(NN_INPUT(nn), mat_row(ti, i));
      nn_forward(nn);
      float y = MAT_AT(NN_OUTPUT(nn), 0, 0);
      //float z = MAT_AT(NN_OUTPUT(nn), 0, 1);
      printf("%zu ^  %zu   %f\n", i, j, y);
    }
  }

  return 0;

  


  //Xor m = xor_alloc();
  //Xor g = xor_alloc();

  //mat_rand(m.w1, 0, 1);
  //mat_rand(m.b1, 0, 1);
  //mat_rand(m.w2, 0, 1);
  //mat_rand(m.b2, 0, 1);


  //float rate = 1e-1;
  
  //printf("cost = %f\n", cost(m, ti, to));
  //for(size_t i = 0; i < 1000*1000; ++i)

  //{
  //  finite_diff(m, g, eps, ti, to);
  //  learn(m, g, rate);
  //}
  //printf("cost = %f\n", cost(m, ti, to));
  
  //for(size_t i = 0; i < 2; ++i) {
  //  for (size_t j = 0; j < 2; ++j) 
  //  {
  //    MAT_AT(m.a0, 0, 0) = i;
  //    MAT_AT(m.a0, 0, 1) = j;
  //    forward_xor(m);
  //    float y = *m.a2.es;
  //    printf("%zu ^ %zu  %f\n", i, j, y);
  //  }
  //}
  //return 0;

}
