#include <vector>
#include <string>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) 
{
  if(nums.size() == 0) return vector<string>();
  vector<string> result;
  string res = "";
  int index = 0;
  for(int i = 0; i < nums.size()-1; ++i)
  {
    if(res.length() == 0)
    {
      res += to_string(nums[i]);
      ++index;
    }
    if((long long)nums[i+1] - (long long)nums[i] <= 1)
    {
      ++index;
    }else{
      if(index > 1)res += "->" + to_string(nums[i]);
      result.push_back(res);
      res = "";
      index = 0;
    }
  }
  if(res.length() > 1) res+= "->";
  res+= to_string(nums[nums.size()-1]);
  result.push_back(res);
  return result;
}
