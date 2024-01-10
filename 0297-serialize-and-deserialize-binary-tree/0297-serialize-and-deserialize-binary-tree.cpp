/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        string str = "";
        str += to_string(root->val) + ",";
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
    TreeNode* helper(stringstream& ss){
        string str;
        getline(ss,str,',');
        if(str == "#") return NULL;
        int data = stoi(str);
        TreeNode* node = new TreeNode(data);
        node->left = helper(ss);
        node->right = helper(ss);
        return node;
        
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));