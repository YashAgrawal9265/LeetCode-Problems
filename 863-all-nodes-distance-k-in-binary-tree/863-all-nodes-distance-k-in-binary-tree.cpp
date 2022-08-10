/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent){
        if(root){
            if(root->left) parent[root->left] = root;
            if(root->right) parent[root->right] = root;
            preorder(root->left,parent);
            preorder(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        preorder(root,parent);
        queue<pair<int,TreeNode*>> q;
        q.push({k,target});
        unordered_map<TreeNode*,int> vis;
        vis[target] = 1;
        vector<int> result;
        while(!q.empty()){
            auto [val,node] = q.front();
            q.pop();
            vis[node] = 1;
            if(val == 0) result.push_back(node->val);
            if(val <= 0) continue;
            if(node->left and !vis[node->left]){
                q.push({val-1,node->left});
            }
            if(node->right and !vis[node->right]){
                q.push({val-1,node->right});
            }
            if(parent[node] and !vis[parent[node]]){
                q.push({val-1,parent[node]});
            }
            
        }
        return result;
    }
};