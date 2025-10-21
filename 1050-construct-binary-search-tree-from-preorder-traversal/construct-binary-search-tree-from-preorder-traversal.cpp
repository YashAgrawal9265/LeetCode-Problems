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
    TreeNode* solve(vector<int>& preorder, int& idx, int n, int mini, int maxi){
        if(idx == n || preorder[idx] > maxi || preorder[idx] < mini) return NULL;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = solve(preorder,idx,n,mini,root->val);
        root->right = solve(preorder,idx,n,root->val,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0, n = preorder.size();
        return solve(preorder,idx,n,-1e8, 1e8);
    }
};