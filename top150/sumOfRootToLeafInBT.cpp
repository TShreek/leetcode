/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        return dfs(root,sum);
    }
    int dfs(TreeNode* node, int sum){
        if(!node) return 0;
        sum = sum*10 + node->val;

        if(!node->left && !node->right){
            return sum;
        }
        return (dfs(node->left,sum) + dfs(node->right,sum));
    }
};
