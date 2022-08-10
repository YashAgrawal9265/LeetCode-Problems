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
        int l = solve(root->left,result);
        int r = solve(root->right,result);
        int x = max(root->val, max(root->val + l, root->val + r));
        result = max(result,max(x,root->val + l + r));

        return x;
    }
    int maxPathSum(TreeNode* root) {
        int result = -1e8;
        solve(root,result);
        return result;
    }
};