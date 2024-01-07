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
    TreeNode* solve(vector<int>& post, int& idx, unordered_map<int,int>& mp, int n, int st, int en){
        if(idx < 0 or st > en){
            return NULL;
        }
        int k = mp[post[idx]];
        TreeNode* node = new TreeNode(post[idx--]);
        node->right = solve(post,idx,mp,n,k+1,en);
        node->left = solve(post,idx,mp,n,st,k-1);
        return node;
        
    }
public:
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        unordered_map<int,int> mp;
        int n = in.size();
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        int idx = n-1;
        return solve(post,idx,mp,n,0,n-1);
    }
};