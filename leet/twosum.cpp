#include <vector>
#include <iostream>

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
  std::vector<int> result; 
  for(int i = 0; i < nums.size(); i++)
    for(int j = i; j < nums.size(); j++)
    {
      if(nums[i] + nums[j] == target)
      {
        result.push_back(i);
        result.push_back(j);
        break;
      }
    }
  return result;
}

int main() 
{
  std::vector<int> as = {10,20,30,45};
  std::vector<int> res = twoSum(as, 65);
  std::cout << res[0] << " " << res[1] << "\n";
  res.clear();
  res = twoSum(as, 50);
  std::cout << res[0] << " " << res[1] << "\n";
  res.clear();
  res = twoSum(as, 75);
  std::cout << res[0] << " " << res[1] << "\n";
  return 0;
}
