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
    bool solve(TreeNode* root, TreeNode* key, vector<TreeNode*>& path){
        if(!root) return false;
        path.push_back(root);
        if(root->val == key->val) return true;
        if(solve(root->left,key,path) || solve(root->right,key,path)) return true;
        path.pop_back();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p1, p2;
        solve(root,p,p1);
        solve(root,q,p2);
        int i = 0, j = 0;
        while(i < p1.size() and j < p2.size()){
            if(p1[i]->val != p2[j]->val){
                return p1[i-1];
            }
            i++,j++;
        }
        if(i == p1.size()) return p1[i-1];
        return p2[j-1];
    }
};