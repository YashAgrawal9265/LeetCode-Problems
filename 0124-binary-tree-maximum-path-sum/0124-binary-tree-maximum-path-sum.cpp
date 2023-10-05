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
        int left = solve(root->left,mxSum);
        int right = solve(root->right,mxSum);
        int sum = root->val+left+right;
        mxSum = max(mxSum,max(sum,max(root->val,max(root->val+left,root->val+right))));
        return max(root->val,max(root->val+left,root->val+right));
    }
    int maxPathSum(TreeNode* root) {
        int mxSum = INT_MIN;
        solve(root,mxSum);
        return mxSum;
    }
};