#include <functional>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };



bool isBalanced(TreeNode* root) 
{
  if(root == nullptr) return true;

  function<int(TreeNode*)> Height = [&](TreeNode* pointer) -> int 
  {
    if(pointer == nullptr) return 0;
    int leftHeight = Height(pointer->left);
    int rightHeight = Height(pointer->right);

    if(leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;
   
    return max(leftHeight, rightHeight) + 1;
  };

  return Height(root) != -1;

}
