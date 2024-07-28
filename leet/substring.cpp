#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int lengthOfLongestSubstring(string s)
{
  vector<char> charVec;
  int res = 0;
  int store = 0;
  for(int i = 0; i < s.length(); i++)
    for(int j = i; j < s.length(); j++)
    {
      char c = s[j]; 
      int cnt = count(charVec.begin(), charVec.end(), c); 
      if(cnt > 0)
      {
        store = charVec.size();
        if(store > res) res = store;
        charVec.clear();
        charVec.push_back(c);
      }
      else
      {
        charVec.push_back(c);
      }
      if(j + 1 == s.length())
      {
        if(charVec.size() > res) res = charVec.size();
      }
    }
  
  return res; 
}

int main() 
{
  int res1 = lengthOfLongestSubstring(" ");
  int res2 = lengthOfLongestSubstring("dvdf");
  printf("%d\n", res1);
  printf("%d\n", res2);
  return 0; 
}
