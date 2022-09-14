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
    int arr[10] = {0};
    int solve(TreeNode* root, int count){
        if(!root) return 0;
        if(!root->left and !root->right){
            arr[root->val]++;
            int odd = 0;
            for(int i=1;i<=9;i++){
                if(arr[i]&1){
                    odd++;
                }
            }
            arr[root->val]--;
            if(count&1){
                if(odd>1) return 0;
                return 1;
            }
            else{
                if(odd) return 0;
                return 1;
            }
        }
        arr[root->val]++;
        int x = solve(root->left,count+1) + solve(root->right,count+1);
        arr[root->val]--;
        return x;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return solve(root,1);
    }
};