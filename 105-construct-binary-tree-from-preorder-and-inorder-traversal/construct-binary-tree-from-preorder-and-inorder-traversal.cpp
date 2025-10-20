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
    TreeNode* solve(int st, int en, int& idx, vector<int>& pre, unordered_map<int,int>& mp){
       
        if(idx >= pre.size()) return NULL;
        if(st > en) return NULL;
        int value = pre[idx++];
        TreeNode* root = new TreeNode(value);
        int mid = mp[value];
        root->left = solve(st,mid-1,idx,pre,mp);
        root->right = solve(mid+1,en,idx,pre,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n= preorder.size();
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        int idx = 0;
        return solve(0,n-1,idx,preorder,mp);
    }
};