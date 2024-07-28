#include <iostream>
#include "fibo.h"
using namespace std;

void fibonacci(int x){
  long long f1{1},f2{1};
  for(int i = 0; i < x - 1; i++){
    if(f1 == f2){
      cout << f1 << " , " << f2;
      f1 += f2;
    }else if(f1 > f2){
      cout << " , " << f1;
      f2 += f1;
    }
    else if(f2 > f1){
      cout << " , " << f2;
      f1 += f2;
    }
  }
  cout << endl;
}
