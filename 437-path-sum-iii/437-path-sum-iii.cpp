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
    void solve(TreeNode* root, long long sum, int& count, int target, unordered_map<long long,long long>& mp){
        if(!root) return;
        sum += root->val;
        if(sum == target) count++;
        if(mp.find(sum - target) != mp.end()){
            
            count += mp[sum-target];
        }
        mp[sum]++;
        solve(root->left,sum,count,target,mp);
        solve(root->right,sum,count,target,mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        unordered_map<long long,long long> mp;
        solve(root,0,count,targetSum,mp);
        return count;
    }
};