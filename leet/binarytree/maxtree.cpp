#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

int max(TreeNode* root)
{
  if(root == nullptr) return 0;
  queue<pair<TreeNode*, int>> memory;
  memory.push({root,1});
  int maxP = 0; 
  while(!memory.empty())
  {
    auto [p1 , index]  = memory.front();
    memory.pop();
    if(p1 == nullptr) continue;
    if(p1 != nullptr)
    {
      memory.push({p1->left, index+1});
      memory.push({p1->right, index+1});
      maxP = max(maxP, index);
    }
  }
  return maxP;
}
