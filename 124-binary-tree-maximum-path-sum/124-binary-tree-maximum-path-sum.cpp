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
    int solve(TreeNode* root, int& result){
        if(!root) return 0;
        int l = max(0,solve(root->left,result));
        int r = max(0,solve(root->right,result));
        result = max(result,root->val + l + r);
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int result = -1e8;
        solve(root,result);
        return result;
    }
};