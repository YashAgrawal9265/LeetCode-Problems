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
        stack<pair<TreeNode*,int>> st;
        while(!st.empty() or root){
            if(root){
                
                st.push({root,1});
                root = root->left;
            }
            else{
                root = st.top().first;
                int num = st.top().second;
                st.pop();
                if(num == 1){
                    st.push({root,2});
                    root = root->right;
                }
                else{
                    result.push_back(root->val);
                    root = NULL;
                }
            }
        }
        return result;
    }
};