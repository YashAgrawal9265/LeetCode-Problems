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
        vector<int> result;
        stack<TreeNode*> st;
        while(!st.empty() or root){
            if(root){
                result.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            else{
                root = st.top();
                st.pop();
                root = root->left;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};