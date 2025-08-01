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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){

            int levelSize = q.size();
            TreeNode* rightMost = nullptr;

            for(int i=0;i<levelSize;i++){
                TreeNode* node = q.front(); q.pop();
                rightMost = node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(rightMost->val);
        }
        return res;
    }
};
