#include <stack>
using namespace std;

struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxTree(TreeNode* root)
{
  if(root == nullptr) return 0;

  stack<pair<TreeNode*, int>> s;
  s.push({root, 1});
  int maxDepth = 0;

  while(!s.empty())
  {
    auto [node, depth] = s.top();
    s.pop();
    if(node != nullptr) 
    {
      maxDepth = max(maxDepth, depth);
      s.push({node->left, depth+1});
      s.push({node->right, depth+1});
    }
  }

  return maxDepth;
}
