#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

vector<int> preorderTraversal(TreeNode* root) 
{
  if(root == nullptr) return vector<int>();
  
  vector<int> result;
  stack<TreeNode*> connects;
  TreeNode* point = root;
  unordered_map<TreeNode*,int> checker;
  while(!connects.empty() || point != nullptr)
  {
      if(point == nullptr)
      {
        point = connects.top();
        connects.pop();
        if(point->right == nullptr || checker.find(point) != checker.end())
        {
          result.push_back(point->val);
          point = nullptr;
          continue;
        }
        else 
        {
          checker[point] = 1;
        }
        point = point->right;
      }else
      {
        connects.push(point);
        point = point->left;
      }
  }
  return result;
}
