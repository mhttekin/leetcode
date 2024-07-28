#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) 
{
  int XOR = nums[0];

  for(int i = 1; i < nums.size(); ++i)
  {
    XOR = XOR ^ nums[i];
  }
  return XOR;
}
