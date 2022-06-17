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
    string solve(TreeNode* root, int& cameras){
        if(!root) return "ok";
        string left = solve(root->left,cameras);
        string right = solve(root->right,cameras);
        if(left == "want" || right == "want"){
            cameras++;
            return "provide";
        }
        else if(left == "provide" || right == "provide"){
            return "ok";
        }
        return "want";
    }
    int minCameraCover(TreeNode* root) {
        int cameras = 0;
        if(solve(root,cameras) == "want") cameras++;
        return cameras;
    }
};