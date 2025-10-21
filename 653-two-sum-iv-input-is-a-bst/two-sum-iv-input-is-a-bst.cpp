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
class BSTIterator{
private:
    stack<TreeNode*> st;
    bool forward;
public:
    BSTIterator(TreeNode* root, bool forward){
        this->forward = forward;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int topEle(){
        return st.top()->val;
    }
    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(forward) pushAll(node->right);
        else pushAll(node->left);
        return node->val;
    }
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            if(forward) root = root->left;
            else root = root->right;
        }
    }

};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root,true);
        BSTIterator right(root,false);
        int i = left.next(), j = right.next();
        while(i < j){
            if(i + j < k){
                i = left.next();
            }
            else if(i + j > k){
                j = right.next();
            }
            else{
                return true;
            }
        }
        return false;
    }
};