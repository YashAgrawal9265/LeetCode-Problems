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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        while(root){
           
            if(!root->left){
                result.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode* temp = root->left;
                while(temp->right and temp->right != root){
                    temp = temp->right;
                }
                if(temp->right == root){
                    result.push_back(root->val);
                    temp->right = NULL;
                    root = root->right;
                }
                else{
                    temp->right = root;
                    root = root->left;
                }
            }
        }
        return result;
    }
};