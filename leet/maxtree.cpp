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


int maxDepth(TreeNode* root) 
{
  TreeNode* p = root;
  if(p == nullptr) return 0;
  int res = 1;
  stack<TreeNode*> connector;
  int index = 0;
  while(p != nullptr || !connector.empty())
  {
    if(p!= nullptr){
      ++index;
      connector.push(p);
      p = p->left;
    }
    else if(p==nullptr && !connector.empty())
    {
      p = connector.top();
      connector.pop();
      p = p->right;
      if(p==nullptr && !connector.empty()) --index;
    }
    if(index > res)
    {
      res = index;
    }

  }
  return res;
}


int main() 
{

}
