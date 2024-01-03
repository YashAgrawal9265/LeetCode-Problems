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
private:
    void preorder(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& parent, TreeNode*& node){
        if(!root) return;
        parent[root] = node;
        preorder(root->left,parent,root);
        preorder(root->right,parent,root);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return {};
        if(k == 0) return {target->val};
        unordered_map<TreeNode*,int> vis;
        unordered_map<TreeNode*,TreeNode*> parent;
        vector<int> result;
        TreeNode* node = NULL;
        preorder(root,parent,node);
        queue<TreeNode*> q;
        q.push(target);
        vis[target] = 1;
        while(!q.empty()){
            int size = q.size();
            k--;
            while(size--){
                TreeNode* node = q.front();
                vis[node] = 1;
                q.pop();
                if(node->left and !vis[node->left]){
                    q.push(node->left);
                }
                if(node->right and !vis[node->right]){
                    q.push(node->right);
                }
                if(parent[node] and !vis[parent[node]]){
                    q.push(parent[node]);
                }
            }
            if(k == 0){
                break;
            }
        }
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};