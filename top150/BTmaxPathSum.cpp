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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

    int dfs(TreeNode* root, int& maxSum){
        if(!root) return 0;
        
        int leftAdd = max(dfs(root->left,maxSum),0);
        int rightAdd = max(dfs(root->right,maxSum),0);
        
        int currentSum = root->val + leftAdd + rightAdd;
        maxSum = max(currentSum, maxSum);

        return root->val + max(leftAdd,rightAdd);
    }
};
