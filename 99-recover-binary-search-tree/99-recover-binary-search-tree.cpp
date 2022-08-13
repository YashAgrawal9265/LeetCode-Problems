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
    void solve(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second, TreeNode*& mid){
        if(!root) return;
        solve(root->left,pre,first,second,mid);
       
        if(pre and root->val < pre->val){
            if(!first and !mid){
                first = pre;
                mid = root;
            }
            else{
                
                second = root;
            }
        }
        pre = root;
        solve(root->right,pre,first,second,mid);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL, *mid = NULL, *second = NULL, *pre = NULL;
        solve(root,pre,first,second,mid);
        if(first and second){
            swap(first->val,second->val);
        }
        else if(first and mid){
            swap(first->val,mid->val);
        }
    }
};