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
        if(!root) return "# ";
        string str = to_string(root->val) + ' ';
        str += serialize(root->left);
        str += serialize(root->right);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return solve(ss);
    }
    
    TreeNode* solve(stringstream& ss){
        string word;
        getline(ss,word,' ');
        if(word == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(word));
        root->left = solve(ss);
        root->right = solve(ss);
        return root;
    }
};

