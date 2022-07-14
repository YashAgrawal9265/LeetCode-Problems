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
    TreeNode* solve(vector<int>& preorder, unordered_map<int,int>& in, int st, int en, int& idx){
        if(st > en or idx == preorder.size()){
            return NULL;
        }
        int k = in[preorder[idx]];
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = solve(preorder,in,st,k-1,idx);
        node->right = solve(preorder,in,k+1,en,idx);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> in;
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]] = i;
        }
        int idx = 0;
        return solve(preorder,in,0,preorder.size()-1,idx);
    }
};