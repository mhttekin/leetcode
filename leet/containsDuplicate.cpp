#include <unordered_map>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums) 
{
  if(nums.size() == 1) return false;
  unordered_map<int, int> map;
  map[nums[0]] = 1;
  for(int i = 1; i < nums.size(); ++i)
  {
    if(map.find(nums[i]) != map.end())
    {
      return true;
    }else 
    {
      map[nums[i]] = 1;
    }
  }
  return false;
}
