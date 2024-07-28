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

TreeNode* invertTree(TreeNode* root) 
{
  if(root == nullptr) return nullptr;
  stack<TreeNode*> points;
  TreeNode* r1 = root;

  while(!points.empty() || r1 != nullptr)
  {
    if(r1 != nullptr)
    {
      TreeNode* temp = r1->right;
      r1->right = r1->left;
      r1->left = temp; 
      points.push(r1);
      r1 = r1->left;
      continue;
    }
    r1 = points.top();
    points.pop();
    r1 = r1->right;
  }
  return root;
}
