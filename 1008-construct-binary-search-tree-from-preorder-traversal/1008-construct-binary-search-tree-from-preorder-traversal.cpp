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
    TreeNode* solve(vector<int>& preorder, int& idx, int maxi){
        if(idx == preorder.size() or preorder[idx] > maxi){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = solve(preorder,idx,node->val-1);
        node->right = solve(preorder,idx,maxi);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return solve(preorder,idx,1e8);
    }
};