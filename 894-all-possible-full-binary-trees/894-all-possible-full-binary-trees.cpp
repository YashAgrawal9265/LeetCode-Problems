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
    vector<TreeNode*> helper(int n, unordered_map<int,vector<TreeNode*>>& dp){
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            vector<TreeNode*> cur;
            cur.push_back(root);
            return cur;
        }
        if(dp.find(n) != dp.end()) return dp[n];
        vector<TreeNode*> cur;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftTree = helper(i,dp);
            vector<TreeNode*> rightTree = helper(n-i-1,dp);
            for(auto l: leftTree){
                for(auto r: rightTree){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    cur.push_back(root);
                }
            }
        }
        return dp[n] = cur;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        unordered_map<int,vector<TreeNode*>> dp;
        return helper(n,dp);
    }
};