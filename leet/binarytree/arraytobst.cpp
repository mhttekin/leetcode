#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


TreeNode* sortedArrayToBST(vector<int>& nums) 
{
  int left = 0, right = nums.size() - 1;
  int half = left + (right-left)/2;
  TreeNode* root = new TreeNode(nums[half]);
  queue<pair<TreeNode*,pair<int,int>>> q;
  q.push({root,{left,right}});
  while(!q.empty())
  {
   TreeNode* tp = q.front().first;
   left = q.front().second.first;
   right = q.front().second.second;
   q.pop();
   half = left + (right - left) / 2;

   if(left < half)
   {
      int left_half = left + (half-left-1) / 2;
      tp->left = new TreeNode(nums[left_half]);
      q.push({tp->left,{left, half-1}});
   }
   if(right > half)
   {
      int right_half = half + 1 + (right-half-1) / 2;
      tp->right = new TreeNode(nums[right_half]);
      q.push({tp->right, {half+1, right}});
   }
  }
  return root;
}
