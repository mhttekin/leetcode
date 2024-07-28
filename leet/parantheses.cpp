#include <stack>
#include <string>
#include <iostream>
using namespace std;

char closing(char c)
{
  switch(c)
  {
    case '{':
      return '}';
      break;
    case '(':
      return ')';
      break;
    case '[':
      return ']';
      break;
    default:
      return '0';
      break;
  }
}

bool isValid(string s) {
  int length = s.length();
  if(length % 2 != 0) return false;
  stack<char> input;
  for(int i = 0; i < length; i++){ 
    if(s[i] == '('||s[i] == '{' || s[i] == '[') input.push(s[i]);
    else{
      if(i == 0 || input.empty()) return false;
      if(closing(input.top()) != s[i]) return false;
      else input.pop();
    }
  }
  if(input.empty()) return true;
  else return false;
}



int main() {
  cout << isValid("(){}]{");
  return 0;
}
