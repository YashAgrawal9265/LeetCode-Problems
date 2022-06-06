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
    vector<TreeNode*> helper(int n){
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            vector<TreeNode*> cur;
            cur.push_back(root);
            return cur;
        }
        vector<TreeNode*> cur;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftTree = helper(i);
            vector<TreeNode*> rightTree = helper(n-i-1);
            for(auto l: leftTree){
                for(auto r: rightTree){
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    cur.push_back(root);
                }
            }
        }
        return cur;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};