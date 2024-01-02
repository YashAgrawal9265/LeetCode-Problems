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
private:
    int solve(TreeNode* root, int& result){
        if(!root) return 0;
        int left = max(0,solve(root->left,result));
        int right = max(0,solve(root->right,result));
        result = max(result,root->val+left+right);
        return root->val + max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        solve(root,result);
        return result;
    }
};