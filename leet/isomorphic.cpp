#include <string>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) 
{
  unordered_map<char, char> sMap;
  unordered_map<char, char> tMap;
  for(int i = 0; i < s.length(); ++i)
  {
    if(sMap.find(s[i]) == sMap.end() && tMap.find(t[i]) == tMap.end() || (sMap[s[i]] == t[i] && tMap[t[i]] == s[i]))
    {
      sMap[s[i]] = t[i];
      tMap[t[i]] = s[i];
    }else return false;
  }
  return true;

}
