#include <stack>
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

bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        stack<pair<TreeNode*, int>> stack;
        stack.push({root, root->val});

        while (!stack.empty()) {
            auto [node, currentSum] = stack.top();
            stack.pop();

            if (node->left == nullptr && node->right == nullptr &&
                currentSum == targetSum) {
                return true;
            }

            if (node->right) {
                stack.push({node->right, currentSum + node->right->val});
            }
            if (node->left) {
                stack.push({node->left, currentSum + node->left->val});
            }
        }
        return false;
}
