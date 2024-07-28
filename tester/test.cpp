#define macro tac()
#include <iostream>
void tac(){
  std::cout << "12";
}
int main() {
  macro;
  return 0;
}
