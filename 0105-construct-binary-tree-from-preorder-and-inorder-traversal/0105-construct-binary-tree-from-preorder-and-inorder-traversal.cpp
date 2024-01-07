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
    TreeNode* solve(vector<int>preorder, int& idx, unordered_map<int,int>& mp, int n, int st, int en){
        if(idx == n or st > en){
            return NULL;
        }
        int x = mp[preorder[idx]];
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = solve(preorder,idx,mp,n,st,x-1);
        node->right = solve(preorder,idx,mp,n,x+1,en);
        return node; 
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        int n = preorder.size();
        return solve(preorder,idx,mp,n,0,n-1);
    }
};