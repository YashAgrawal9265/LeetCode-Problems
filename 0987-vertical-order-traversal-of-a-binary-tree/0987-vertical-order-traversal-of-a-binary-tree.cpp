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
    bool static cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.second < b.second) return true;     
        if(a.second == b.second){
            return a.first < b.first;
        }
        return false;
    }
    void solve(TreeNode* root, unordered_map<int,vector<pair<int,int>>>& mp, int& mnCol, int& mxCol, int col,int row){
        if(!root) return;
        mp[col].push_back({root->val,row});
        mnCol = min(mnCol,col);
        mxCol = max(mxCol,col);
        solve(root->left,mp,mnCol,mxCol,col-1,row+1);
        solve(root->right,mp,mnCol,mxCol,col+1,row+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        unordered_map<int,vector<pair<int,int>>> mp;
        int mnCol = INT_MAX, mxCol = INT_MIN;
        solve(root,mp,mnCol,mxCol,0,0);
        vector<vector<int>> result;
        for(int i=mnCol;i<=mxCol;i++){
            sort(mp[i].begin(),mp[i].end(),cmp);
            vector<int> temp;
            for(auto &it:mp[i]){
                temp.push_back(it.first);
            }
            result.push_back(temp);
        }
        return result;
    }
};