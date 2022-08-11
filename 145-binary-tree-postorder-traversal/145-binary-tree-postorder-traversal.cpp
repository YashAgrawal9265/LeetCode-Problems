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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> result;
        while(cur){
            if(!cur->right){
                result.push_back(cur->val);
                cur = cur->left;
            }
            else{
                TreeNode* temp = cur->right;
                while(temp->left and temp->left != cur){
                    temp = temp->left;
                }
                if(temp->left == NULL){
                    result.push_back(cur->val);
                    temp->left = cur;
                    cur = cur->right;
                }
                else{
                    temp->left = NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};