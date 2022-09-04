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
bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
class Solution {
public:
    int mnCol = INT_MAX;
    int mxCol = INT_MIN;
    void solve(TreeNode* root, unordered_map<int,vector<pair<int,int>>>& mp, int col, int row){
        if(!root) return;
        mnCol = min(mnCol,col);
        mxCol = max(mxCol,col);
        mp[col].push_back({root->val,row});
        solve(root->left,mp,col-1,row+1);
        solve(root->right,mp,col+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int,vector<pair<int,int>>> mp;
        
        solve(root,mp,0,0);
        vector<vector<int>> result;
        for(int i=mnCol; i<= mxCol; i++){
            sort(mp[i].begin(),mp[i].end(),cmp);
            vector<int> temp;
            for(auto &it: mp[i]) temp.push_back(it.first);
            result.push_back(temp);
            
        }
        return result;
        
    }
};