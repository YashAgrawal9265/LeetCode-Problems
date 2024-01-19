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
    void solve(TreeNode* root, TreeNode*& prev, bool& ans){
        if(!root) return;
        
        solve(root->left,prev,ans);
        if(prev){
            if(prev->val >= root->val) ans = false;
        }
        prev = root;
        solve(root->right,prev,ans);
    }
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        bool ans = true;
        solve(root,prev,ans);
        return ans;
    }
};