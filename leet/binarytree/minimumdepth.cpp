#include <functional>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int minDepth(TreeNode* root) 
{
  if(root == nullptr) return 0;

  function<int(TreeNode*)> Minimum = [&](TreeNode* pointer) -> int 
  {
    if(pointer == nullptr) return 0;
    int leftHeight = Minimum(pointer->left);
    int rightHeight = Minimum(pointer->right);
    
    if(leftHeight != 0 && rightHeight != 0) 
      return min(leftHeight, rightHeight) + 1;
    else return max(leftHeight, rightHeight) + 1;
  };
  
  return Minimum(root);
}
