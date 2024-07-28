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

bool isSym(TreeNode* root)
{
  if(root == nullptr) return true;
  queue<TreeNode*> memory;
  memory.push(root);
  memory.push(root);
  
  while(!memory.empty())
  {
    TreeNode* p1 = memory.front();
    memory.pop();
    TreeNode* p2 = memory.front();
    memory.pop();
    if(p1 == nullptr && p2 == nullptr) continue;
    if(p1 == nullptr || p2 == nullptr) return false;
    if(p1->val != p2->val) return false;
    else
    {
      memory.push(p1->left);
      memory.push(p2->right);
      memory.push(p1->right);
      memory.push(p2->left);
    }
  }
  return true;
}

