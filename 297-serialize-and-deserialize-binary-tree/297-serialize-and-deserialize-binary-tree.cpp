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
        string result = "";
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() or cur){
            if(cur){
                result += to_string(cur->val) + ' ';
                st.push(cur);
                cur = cur->left;
            }
            else{
                result += "# ";
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }
        return result;
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
        if(word.size() == 0) return NULL;
        TreeNode* root = new TreeNode(stoi(word));
        root->left = solve(ss);
        root->right = solve(ss);
        return root;
    }
};

