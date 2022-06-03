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
    static bool cmp(pair<int,int> a, pair<int,int> b){
        if(a.first < b.first) return true;
        else if(a.first == b.first) return a.second < b.second;
        return false;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<pair<TreeNode*,int>> q;
        unordered_map<int,vector<pair<int,int>>> mp;
        int mnCol = INT_MAX, mxCol = INT_MIN;
        int level = 0;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            while(size--){
               TreeNode* node = q.front().first;
                int col = q.front().second;
                q.pop();
                mnCol = min(mnCol,col);
                mxCol = max(mxCol,col);
                mp[col].push_back({level,node->val});
                if(node->left) q.push({node->left,col-1});
                if(node->right) q.push({node->right,col+1}); 
            }
            level++;
        }
        for(int i=mnCol;i<=mxCol;i++){
            sort(mp[i].begin(),mp[i].end(),cmp);
            vector<int> temp;
            for(auto it: mp[i]){
                temp.push_back(it.second);
            }
            result.push_back(temp);
        }
        return result;
        
    }
};