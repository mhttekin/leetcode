#include <stack>
using namespace std;

struct TreeNode 
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr){}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
  if(p == nullptr && q == nullptr) return true;
  if(p == nullptr || q == nullptr) return false;

  stack<TreeNode*> stackP, stackQ;
  stackP.push(p);
  stackQ.push(q);

  while(!stackP.empty() && !stackQ.empty()) 
  {
    TreeNode* nodeP = stackP.top();
    TreeNode* nodeQ = stackQ.top();
    stackP.pop();
    stackQ.pop();

    if(nodeP-> val != nodeQ-> val) return false;

    if(nodeP->right != nullptr && nodeQ->right != nullptr)
    {
      stackP.push(nodeP->right);
      stackQ.push(nodeQ->right);
    }
    else if(nodeP->right != nodeQ->right) return false;

    if(nodeP->left != nullptr && nodeQ->left != nullptr)
    {
      stackP.push(nodeP->left);
      stackQ.push(nodeQ->left);
    }
    else if(nodeP->left != nodeQ->left) return false;
  }
  
  return stackP.empty() && stackQ.empty();
}
