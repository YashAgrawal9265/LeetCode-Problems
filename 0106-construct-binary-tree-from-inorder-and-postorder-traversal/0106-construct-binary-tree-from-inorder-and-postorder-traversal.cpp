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
    TreeNode* solve(vector<int>& postorder, unordered_map<int,int>& mp, int& idx, int st, int en){
        if(idx < 0 || st > en) return NULL;
        int k = mp[postorder[idx]];
        TreeNode* root = new TreeNode(postorder[idx--]);
        root->right = solve(postorder,mp,idx,k+1,en);
        root->left = solve(postorder,mp,idx, st, k-1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int idx = postorder.size()-1;
        return solve(postorder,mp,idx,0,inorder.size()-1);
    
    }
};