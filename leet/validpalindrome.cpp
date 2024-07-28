#include <string>
using namespace std;

bool isPalindrome(string s)
{
  string result = "", real = "";
  int length = s.length();
  for(int i = length-1; i >= 0; --i)
  {
    if(isalpha(s[i]) || isdigit(s[i]))
    {
      result += s[i];
    }
  }
  for(int i = real.length()-1; i >= 0; --i)
  {
    real += result[i];
  }
  return result == real ? true : false;
}
