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
    vector<TreeNode*> helper(int st, int en){
        if(st > en){
            return {NULL};
        }
        vector<TreeNode*> cur;
        for(int i=st;i<=en;i++){
            vector<TreeNode*> leftTree = helper(st,i-1);
            vector<TreeNode*> rightTree = helper(i+1,en);
            for(auto &l: leftTree){
                for(auto &r: rightTree){
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
         return helper(1,n);
    }
};