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
    int solve(TreeNode* root, int mxVal){
        if(!root) return 0;
        int count = 0;
        if(root->val >= mxVal) count++;
        count += solve(root->left,max(root->val,mxVal));
        count += solve(root->right,max(root->val,mxVal));
        return count;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};