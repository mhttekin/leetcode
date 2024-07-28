#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  int size = strs.size();
  bool contains = true;
  string tester = strs[0];
  
  if(tester == "") return "";
  while(tester.length() > 0) 
  {
    contains = true;
    for(int i = 1; i < size; i++) 
    {
      if(strs[i].find(tester) > 200) contains = false; 
    }
    if(contains == false) tester.erase(tester.length() - 1, 1);
    else break;
  }
  if(tester == "") return "";
  else return tester;
}

int main() {

  vector<string> strs = {"ap", "app", "aple", "apar"};
  
  string aa = "c";
  string bb = "acc";
  string cc = "ccc";

  printf("%s\n", bb.find(aa) > 0 ? "true" : "false");
  printf("%s\n", cc.find(aa) > 0 ? "true" : "false");
  cout << strs[1].find(strs[0]) << "\n";
  cout << strs[2].find(strs[0]) << "\n";  
  cout << strs[3].find(strs[0]) << "\n";
  return 0;
}
