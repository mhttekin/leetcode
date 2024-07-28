#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
  int size = strs.size();
  bool contains = true;
  string tester = strs[0];
  string result = "";
  string store = "";
  unsigned long index {202};
  for(int j = 0; j < tester.length(); j++)
  {
    contains = true;
    char c = tester[j];
    for(int i = 1; i < strs.size(); i++)
    {
      printf("%lu\n", strs[i].find(store+c));
      if(strs[i].find(c) > 200 ) 
      {
        contains = false;

      }
      else if(strs[i].find(store + c) > 200)
      {
        contains = false;
        if(store.length() == 1) store = c;
      }
    } 
    if (contains == true) store += c;
     
    if(store.length() > result.length()) result = store;
  }
  return result;
}

  


int main()
{
  vector<string> strs = {"labal", "ffabal" };
  
  //vector<string> strs1 = {"dog", "racecar", "car"};
  string name = longestCommonPrefix(strs);
  cout << name << "\n";
  
}







