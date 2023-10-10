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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxi = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int st = q.front().second, en;
            while(size--){
                TreeNode* node = q.front().first;
                int curIdx = q.front().second;
                en = curIdx;
                q.pop();
                if(node->left){
                    q.push({node->left,1LL*2*(curIdx-st)+1});
                }
                if(node->right){
                    q.push({node->right,1LL*2*(curIdx-st)+2});
                }
            }
            maxi = max(maxi,en-st+1);
        }
        return maxi;
    }
};