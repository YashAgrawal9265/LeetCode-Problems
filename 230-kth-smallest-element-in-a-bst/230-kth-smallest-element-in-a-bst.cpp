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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int result = -1;
        while(cur){
            if(!cur->left){
                k--;
                if(k == 0) result = cur->val;
                cur = cur->right;
            }
            else{
                TreeNode* temp = cur->left;
                while(temp->right and temp->right != cur){
                    temp = temp->right;
                }
                
                if(temp->right == NULL){
                    temp->right = cur;
                    cur = cur->left;
                    
                }
                else{
                    k--;
                    if(k == 0) result =  cur->val;
                    temp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        
        return result;
    }
};