#include <vector>
#include <stack>
using namespace std;

struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> inorderTraversal(TreeNode* root) 
{
  if(root == nullptr) return vector<int>();
  vector<int> result;
  stack<TreeNode*> bum;
  TreeNode* pointer = root;
  while(pointer != nullptr || !bum.empty())
  {
    while(pointer != nullptr)
    {
      bum.push(pointer);
      pointer = pointer->left;
    }
    
    pointer = bum.top();
    bum.pop();
    result.push_back(pointer->val);
    pointer = pointer->right;
  }

  return result;
}

int main()
{

}
