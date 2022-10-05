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
    void solve(TreeNode* root, int level, int depth, int val){
        if(!root) return;
        if(level == depth - 1){
            TreeNode* leftTemp = new TreeNode(val);
            TreeNode* rightTemp = new TreeNode(val);
            leftTemp->left = root->left;
            root->left = leftTemp;
            rightTemp->right = root->right;
            root->right = rightTemp;
        }
        solve(root->left,level+1,depth,val);
        solve(root->right,level+1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        solve(root,1,depth,val);
        return root;
    }
};