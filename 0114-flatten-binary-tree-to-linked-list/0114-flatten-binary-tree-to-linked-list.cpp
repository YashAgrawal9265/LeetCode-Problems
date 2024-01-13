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
    void solve(TreeNode* root, TreeNode*& pre){
        if(!root) return;
        solve(root->right,pre);
        solve(root->left,pre);
        root->right = pre;
        pre = root;
        root->left = NULL;
    }
public:
    void flatten(TreeNode* root) {
        TreeNode* pre = NULL;
        solve(root,pre);
    }
};