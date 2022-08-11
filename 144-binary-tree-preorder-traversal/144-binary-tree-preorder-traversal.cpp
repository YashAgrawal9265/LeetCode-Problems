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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> result;
        while(cur){
            if(!cur->left){
                result.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right and temp->right != cur){
                    temp = temp->right;
                }
                if(temp->right == NULL){
                    result.push_back(cur->val);
                    temp->right = cur;
                    cur = cur->left;
                }
                else{
                    temp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }
    
    
};