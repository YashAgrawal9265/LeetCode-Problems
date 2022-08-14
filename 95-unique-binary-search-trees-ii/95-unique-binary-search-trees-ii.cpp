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
    vector<TreeNode*> solve(int st, int en){
        if(st > en){
            return {NULL};
        }
        vector<TreeNode*> cur;
        for(int i=st;i<=en;i++){
            vector<TreeNode*> left = solve(st,i-1);
            vector<TreeNode*> right = solve(i+1,en);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    cur.push_back(root);
                }
            }
        }
        return cur;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};