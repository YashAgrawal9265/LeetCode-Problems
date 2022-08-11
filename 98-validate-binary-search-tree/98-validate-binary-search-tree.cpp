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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val > maxi or root->val < mini) return false;
        return solve(root->left,mini,1LL*root->val-1) and solve(root->right,1LL*root->val+1,maxi);
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);
    }
};