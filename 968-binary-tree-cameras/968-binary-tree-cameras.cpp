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
    string solve(TreeNode* root, int& camera){
        if(!root) return "ok";
        string left = solve(root->left,camera);
        string right = solve(root->right,camera);
        if(left == "want" or right == "want"){
            camera++;
            return "provide";
        }
        if(left == "provide" or right == "provide"){
            return "ok";
        }
        return "want";
    }
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        if(solve(root,camera) == "want") camera++;
        return camera;
    }
};