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
    bool path(TreeNode* root, int target, string& str){
        if(!root) return false;
        if(root->val == target){
            return true;
        }
        bool left = path(root->left,target,str);
        if(left){
            str += 'L';
            return true;
        }
        bool right = path(root->right,target,str);
        if(right){
            str += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int st, int dst) {
        string rootToSt = "";
        path(root,st,rootToSt);
        reverse(rootToSt.begin(),rootToSt.end());
        string rootToDst = "";
        path(root,dst,rootToDst);
        reverse(rootToDst.begin(),rootToDst.end());
        int i=0,j=0;
        while(i<rootToSt.size() and j < rootToDst.size()){
            if(rootToSt[i] == rootToDst[j]) i++,j++;
            else{
                break;
            }
        }
        string result = "";
        while(i<rootToSt.size()){
            result += 'U';
            i++;
        }
        while(j<rootToDst.size()) result += rootToDst[j++];
        return result;
        
    }
};