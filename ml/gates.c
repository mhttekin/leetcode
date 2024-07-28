#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float sigmoidf(float x)
{
  return 1.f / (1.f + expf(-x));
}
typedef float sample[3];
// OR-GATE
sample or_train[] = 
{
  {0,0,0},
  {1,0,1},
  {0,1,1},
  {1,1,1},
};
sample and_train[] = 
{
  {0,0,0},
  {1,0,0},
  {0,1,0},
  {1,1,1},
};
sample nand_train[] = 
{
  {0,0,1},
  {1,0,1},
  {0,1,1},
  {1,1,0},
};
sample *train = and_train;
size_t train_size = 4;
float rand_float(void)
{
  return (float) rand() / (float) RAND_MAX;
};

float cost(float w1, float w2, float b)
{
  float result = 0.0f;
  for(size_t i = 0; i < train_size; ++i)
  {
    float x1 = train[i][0];
    float x2 = train[i][1];
    float y = sigmoidf(x1*w1 + x2*w2 +b);
    float z = y - train[i][2];
    result += z*z;
  } 
  result /= train_size;
  return result; 
}

void dcost(float w1, float w2, float b,
    float *dw1, float *dw2, float *db)
{
  *dw1 = 0;
  *dw2 = 0;
  *db = 0;
  for(size_t i = 0; i < train_size; ++i)
  {
     float xi = train[i][0];
     float yi = train[i][1];
     float zi = train[i][2];
     float ai = sigmoidf(xi*w1 + yi*w2 + b);
     float di = 2*(ai - zi)*ai*(1 - ai); 
     *dw1 += di*xi;
     *dw2 += di*yi;
     *db += di;
  }
  *dw1 /= train_size;
  *dw2 /= train_size;
  *db /= train_size;
}

int main(void)
{
  srand(time(NULL));
  float w1 = rand_float();
  float w2 = rand_float();
  float b = rand_float();
  printf("w1: %f w2: %f bias: %f\n", w1, w2, b);
  float rate = 1e-1;
  float dw1 = 0;
  float dw2 = 0;
  float db = 0;
  for(size_t i = 0; i < 1000*10; ++i)
  {
    dcost(w1, w2, b, &dw1, &dw2, &db);
    w1 -= dw1*rate;
    w2 -= dw2*rate;
    b -= db*rate;
  }
  //printf("w1 = %f w2 = %f bias = %f c = %f\n", w1, w2, b, cost(w1,w2,b));
  for(size_t i = 0; i < 2; ++i)
  {
    for(size_t j = 0; j < 2; ++j)
    {
      printf("%zu | %zu = %f\n", i, j, sigmoidf(i*w1+j*w2+b));
    }
  }

  return 0;
}
