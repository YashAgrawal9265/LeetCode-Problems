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
    int inorderPred(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val < key){
            root->right =  deleteNode(root->right,key);
        }
        else if(root->val > key){
            root->left = deleteNode(root->left,key);
        }
        else{
            if(!root->left and !root->right) return NULL;
            if(!root->left) return root->right;
            if(!root->right) return root->left;
            int val = inorderPred(root->left);
            root->val = val;
            root->left = deleteNode(root->left,val);
        }
        return root;
    }
};