#include <string>
#include <vector>
#include <iostream>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        bool contains = true;
        string tester = strs[0];
        string result = "";
        string store = ""; 
        for(int j = 0; j < tester.length(); j++)
        { 
            contains = true;
            char c = tester[j];
            for(int i = 1; i < strs.size(); i++)
            {
                if(result.length() != j) contains = false;
                printf("%lu\n", result.length());
                if(strs[i].find(c) > 1) contains = false;
                else if(strs[i].find(result + c) > 1)
                {
                    
                    contains = false;
                }
                printf("%lu\n", strs[i].find(result+c));
            } 
            if (contains == true) result += c;
        }
        return result;
    }

int main() {
   vector<string> strs = {"flower", "flower", "flower","flower"};
   string name = longestCommonPrefix(strs);
   cout << name << "\n";

}
