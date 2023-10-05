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
    int solve(TreeNode* root, int& mxSum){
        if(!root) return 0;
        int left = max(solve(root->left,mxSum),0);
        int right = max(solve(root->right,mxSum),0);
        mxSum = max(mxSum,root->val+left+right);
        return max(root->val+left,root->val+right);
        
    }
    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        solve(root,mxSum);
        return mxSum;
    }
};