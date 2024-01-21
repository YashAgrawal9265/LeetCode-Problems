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
private:
    string solve(TreeNode* root){
        if(!root) return "#";
        string str = "";
        str += root->val;
        str += solve(root->left);
        str += solve(root->right);
        return str;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string str1 = solve(root), str2 = solve(subRoot);
        if(str1.find(str2) != string::npos) return true;
        return false;
    }
};