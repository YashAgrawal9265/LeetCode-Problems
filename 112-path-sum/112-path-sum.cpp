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
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        sum += root->val;
        if(!root->left and !root->right){
            sum -= root->val;
            return sum + root->val == targetSum;
        }
        if(hasPathSum(root->left,targetSum) or hasPathSum(root->right,targetSum)) return true;
        sum -= root->val;
        return false;
    }
};