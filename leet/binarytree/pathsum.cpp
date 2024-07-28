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

bool hasPathSum(TreeNode* root, int targetSum) 
{
  if(root == nullptr) return false;
  stack<TreeNode*> points; 
  TreeNode* pointer = root;
  int result = 0;
  while(!points.empty() || pointer != nullptr)
  {
    if(pointer != nullptr)
    {
      result += pointer->val;
      points.push(pointer);
      pointer = pointer->left;
    }
    if(result == targetSum) return true;
    if(result > targetSum)
    {
      if(!points.empty())
      {
        pointer = points.top();
        points.pop();
        if(pointer->right == nullptr) result -=pointer->val;
        pointer = pointer->right;
      }else return false;
    }
  }
  return result == targetSum ? true : false;
  //put the treenode* to stack and val to vector
  // in while loop check if pointer==nullptr \\ the vector elements fill to sum if true then
  // if sum smaller than push the left side of pointer to stack
  // if bigger and stack not empty remove the last element and go back to that pointer and go right
  //
  //
  //
  //Time Limit Exceeded ...
  //Deleted vector still time limit exceeded.
}
