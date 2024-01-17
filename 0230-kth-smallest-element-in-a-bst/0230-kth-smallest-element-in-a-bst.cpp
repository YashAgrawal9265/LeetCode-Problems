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
    void solve(TreeNode* root, int& k, int& result){
        if(!root) return;
        solve(root->left,k,result);
        k--;
        if(k == 0) result = root->val;
        solve(root->right,k,result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        solve(root,k,result);
        return result;
    }
};