#include <vector>
#include <functional>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* vecToTree(vector<int>& nums)
{
  function<TreeNode*(int,int)> Insert = [&](int left, int right) -> TreeNode*
  {
    if(left > right) return nullptr;
    int mid = left + (right - left) / 2;
    
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = Insert(left, mid-1);
    node->right = Insert(mid+1, right);

    return node;
  };
  
  return Insert(0, nums.size());
}
