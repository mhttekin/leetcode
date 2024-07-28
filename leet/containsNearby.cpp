#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
  if(nums.size() == 1) return false;
  
  unordered_map<int, int> map;
  map[nums[0]] = 0;
  for(int i = 1;i < nums.size(); ++i)
  {
    if(map.find(nums[i]) != map.end())
    {
      if(abs(map[nums[i]] - i) < k)
        return true;
    }
    else map[nums[i]] = i;
  }
  return false;
}
