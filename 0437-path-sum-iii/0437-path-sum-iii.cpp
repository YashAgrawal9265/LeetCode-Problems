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
    void solve(TreeNode* root, int k,unordered_map<long long,int>& mp, long long& sum, int& count){
        if(!root) return;
        sum += root->val;
        if(sum == k) count++;
        if(mp.find(sum - k) != mp.end()) count += mp[sum-k];
        mp[sum]++;
        solve(root->left,k,mp,sum,count);
        solve(root->right,k,mp,sum,count);
        mp[sum]--;
        sum -= root->val;
    }
public:
    int pathSum(TreeNode* root, int target) {
        unordered_map<long long,int> mp;
        long long sum = 0;
        int count = 0;
        solve(root,target,mp,sum,count);
        return count;
    }
};