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

int countNodes(TreeNode* root)
{
  if(root == nullptr) return 0;
  stack<TreeNode*> points;
  int count = 0;
  while(root != nullptr || !points.empty())
  {
    if(root != nullptr)
    {
      ++count;
      points.push(root);
      root = root->left;
      continue;
    }
    else
    {
      root = points.top();
      points.pop();
      root = root->right;
    }
  }
  return count;
}
