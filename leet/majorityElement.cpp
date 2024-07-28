#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int>& nums) 
{
  if(nums.size() == 1) return nums[0];

  int result = 0;
  unordered_map<int, int> map;
  for(int i = 0; i < nums.size(); ++i)
  {
    map[nums[i]] += 1;
    if(map[nums[i]] > map[result]) result = nums[i];
   // auto it = map.find(nums[i]);
   // if(it != map.end()) it->second += 1;
   // else map[nums[i]] = 1;
   // if(map.at(nums[i]) > result) result = nums[i];
  }
  return result;
}

int main() 
{

}
