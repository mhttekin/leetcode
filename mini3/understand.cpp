#include <cstdio>


void add(int&v )
{
  v+= 1;
  
}
int main() {
    
  int x = 1;
  add(x);
  

  printf("result: %d\n", x);
}
