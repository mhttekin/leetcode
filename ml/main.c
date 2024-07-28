#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float train[][2] = 
{
  {0,0},
  {1,4},
  {2,8},
  {3,12},
  {4,16},
};
#define train_size ((float) sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
  return (float) rand() / (float) RAND_MAX;
};

float cost(float w)
{
  float result = 0.0f;
  for(size_t i = 0; i < train_size; ++i)
  {
    float x = train[i][0];
    float y = x*w;
    float z = y - train[i][1];
    result += z*z;
  } 
  result /= train_size;
  return result; 
}

float dcost(float w)
{
  float result = 0.0f;
  size_t n = train_size;
  for(size_t i = 0; i < n; ++i)
  {
    result+= 2*((train[i][0]*w) - train[i][1])*train[i][0];
  }
  return (float) result/n;
}


int main()
{
  // cost function
  srand(time(NULL));
  float w = rand_float() * 100.0f;
  float rate = 1e-1;
  printf("w: %f  cost: %f\n",w,cost(w));
  for(size_t i = 0; i < 50; ++i){
    float dw = dcost(w);
    w -= rate*dw;
  }
  printf("w: %f cost: %f\n",w,cost(w));
  for(size_t i = 0; i < train_size; ++i)
  {
    printf("%zu == %f\n", i , w);
  }
  return 0;
}

