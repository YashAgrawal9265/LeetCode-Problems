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
    string solve(TreeNode* root){
        if(!root) return "";
        string str = to_string(root->val);
        if((!root->left and root->right) or root->left){
            str += '(' + solve(root->left) + ')';
        }
        if(root->right){
            str += '(' + solve(root->right) + ')';
        }
        return str;
    }
    string tree2str(TreeNode* root) {
        return solve(root);
    }
};