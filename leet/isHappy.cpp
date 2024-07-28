#include <cmath>
using namespace std;

bool isHappy(int n)
{
  int i = 0, index = 0;
  while(n != 1 && index < 30)
  {
    while(n > 0)
    {
      i += pow(n%10, 2);
      n /= 10;
    }
    n = i;
    ++index;
    i = 0;
  }
  return n == 1;
}

int main()
{

}
