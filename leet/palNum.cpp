#include <stack>
#include <string>
#include <cmath>
using namespace std;
bool isPalindrome(int x) {
  stack<char> store;
  auto s = to_string(x);
  for(char c : s)
  {
    store.push(c);
  }
  int size = store.size();
  string palindrome = ""; 
  for(int i = size - 1; i >= 0; i--)
  {
    char c = store.top();
    palindrome += c;  
    store.pop();
  }
  if(palindrome == s) return true;
  else return false;
}

int main()
{
  printf("%s\n", isPalindrome(100010001) ? "true" : "false");
  printf("%d\n", isPalindrome(10101) );
  printf("%d\n", isPalindrome(1));

}

