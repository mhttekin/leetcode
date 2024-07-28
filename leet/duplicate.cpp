#include <vector>
#include <iostream>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
  if(nums.size() == 1) return nums.size();
  if(nums.size() == 2){
    if(nums[0] == nums[1]) nums.erase(nums.begin());
  }
  for(auto i = nums.begin(); *i != *(nums.end()-1) ;)
  {
    if(i != nums.end() && *i == *(i+1)) i = nums.erase(i);
    else ++i;
  }

  return nums.size();
}

int main() 
{
  vector<int> ba = {1,2,3,4,4,5,6};
  vector<int> ca = {1,1};

  removeDuplicates(ba);
  removeDuplicates(ca);

  for(auto i : ca)
  {
    cout << i << " ";
  }
  

  return 0;
 
   
  


}
