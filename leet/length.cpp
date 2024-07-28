#include <string>
#include <iostream>
using namespace std;

int lengthOfLastWord(string s) 
{
  int length = s.length();
  string res = "";
  int j = 0;
  for(int i = length -1 ; i >= 0; --i)
  {
    if(s[i] == ' ' && i != length-1 && s[i+1] != ' '){
      res = s.substr(i+1, (length-i-j-1));
      return res.length();
    } 
    else if(s[i] == ' ') ++j;
     
  }
  return s.length();
}

int main() 
{
  string x =  "luffy is still joyboy  ";
  string y = "   fly me   to   the asdsadmoon                             ";
  cout << lengthOfLastWord(x) << "\n";
  cout << lengthOfLastWord(y) << "\n";
  
  return 0;
}
