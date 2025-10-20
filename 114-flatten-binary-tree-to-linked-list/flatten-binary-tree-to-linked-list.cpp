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
    void solve(TreeNode* root, TreeNode*& temp){
        if(!root) return;
        solve(root->right,temp);
        solve(root->left,temp);
        root->right = temp;
        root->left = NULL;
        temp = root;
    }
    void flatten(TreeNode* root) {
        TreeNode* temp = NULL;
        solve(root,temp);
    }
};