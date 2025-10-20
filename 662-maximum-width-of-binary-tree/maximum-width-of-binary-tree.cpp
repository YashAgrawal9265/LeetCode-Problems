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
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});

        int maxi = -1;
        while(!q.empty()){
            int size = q.size();
            int firstNodeIdx = q.front().first;
            int lastNodeIdx;
            while(size--){
                TreeNode* node = q.front().second;
                int idx = q.front().first;
                q.pop();
                if(node->left){
                    q.push({1LL*2*(idx-firstNodeIdx) + 1,node->left});
                }
                if(node->right){
                    q.push({1LL*2*(idx-firstNodeIdx) + 2,node->right});
                }
                lastNodeIdx = idx;
            }
            maxi = max(maxi,lastNodeIdx-firstNodeIdx+1);
        }
        return maxi;
    }
};