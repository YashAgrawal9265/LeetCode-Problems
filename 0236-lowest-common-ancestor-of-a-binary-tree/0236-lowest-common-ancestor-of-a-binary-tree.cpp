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
    bool solve(TreeNode* root, vector<TreeNode*>& path, int p){
        if(!root) return false;
        path.push_back(root);
        if(root->val == p){
            return true;
        }
        bool left = solve(root->left,path,p);
        if(left) return true;
        bool right = solve(root->right,path,p);;
        if(right) return true;
        path.pop_back();
        return false;
            
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<TreeNode*> path1,path2;
        solve(root,path1,p->val);
        solve(root,path2,q->val);
        int i=0,j=0;
        
        while(i<path1.size() and j < path2.size()){
            if(path1[i]->val != path2[j]->val) return path1[i-1];
            i++,j++;
        }
        if(i<path1.size()) return path2[j-1];
        return path1[i-1];
    }
};