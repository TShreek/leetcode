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
    unordered_map<int,int> inorderMap;
    int postOrderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        postOrderIndex = n-1;

        for(int i=0;i<n;i++){
            inorderMap[inorder[i]]=i;
        }

        return build(postorder, 0, n-1);
    }
    TreeNode* build(vector<int>& postorder, int left, int right){
        if(left > right) return nullptr;

        int rootval = postorder[postOrderIndex--];
        TreeNode* root = new TreeNode(rootval);

        int index = inorderMap[rootval];

        root->right = build(postorder, index+1, right);
        root->left = build(postorder, left,index-1);

        return root;
    }
};
