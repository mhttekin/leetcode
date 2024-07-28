#include <stack>
using namespace std;
//pretty shit but well tried. 
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
  bool control = true;
  if(p == nullptr && q == nullptr) return control;
  else if(p == nullptr && q != nullptr) return false;
  stack<TreeNode*> controlPointX;
  stack<TreeNode*> controlPointY;
  TreeNode* pointx = p, *pointy = q;
  while(pointx != nullptr || pointy != nullptr || !controlPointX.empty() || !controlPointY.empty())
  {
    if(pointx == nullptr && pointy == nullptr)
    {
      if((controlPointX.empty() && !controlPointY.empty()) || (!controlPointX.empty() && controlPointY.empty()))
      {
        control = false;
        return control;
      }else
      {
        pointx = controlPointX.top();
        pointy = controlPointY.top();
        pointx = pointx->right;
        pointy = pointy->right;
        controlPointX.pop();
        controlPointY.pop();
      }
    }
   if(pointx->val != pointy->val) 
    {
      control = false;
      return control;
    }
    controlPointX.push(pointx);
    controlPointY.push(pointy);
    pointx = pointx->left;
    pointy= pointy->left;
  }
  return control; 
}
