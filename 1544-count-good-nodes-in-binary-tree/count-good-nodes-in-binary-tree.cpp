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
    void solve(TreeNode* root, int& count, int maxi){
        if(!root) return;
        if(root->val >= maxi){
            count++;
            maxi = root->val;
        }
        solve(root->left,count,maxi);
        solve(root->right,count,maxi);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        solve(root,count,INT_MIN);
        return count;
    }
};