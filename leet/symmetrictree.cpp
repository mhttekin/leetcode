#include <queue>
using namespace std;
//bread first search && palindrome
struct TreeNode 
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr){}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSymmetric(TreeNode* root)
{
  queue<TreeNode*> level; 
  
  if(root->left == nullptr && root->right == nullptr)
    return true;
  
  level.push(root);
  level.push(root);
  while(!level.empty())
  {
    TreeNode* pointer1 = level.front();
    level.pop();
    TreeNode* pointer2 = level.front();
    level.pop();

    if(pointer1 == nullptr && pointer2 == nullptr)continue;
    if(pointer1 == nullptr || pointer2 == nullptr)return false;
    if(pointer1->val != pointer2->val) return false;
    
    level.push(pointer1->left);
    level.push(pointer2->right);
    level.push(pointer1->right);
    level.push(pointer2->left);

  }
  return true;
  
}
            
