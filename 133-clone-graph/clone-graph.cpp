/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* dupNode, unordered_map<Node*,Node*>& vis){
        vis[node] = dupNode;
        for(auto it:node->neighbors){
            if(!vis[it]){
                Node* dupChild = new Node(it->val);
                dupNode->neighbors.push_back(dupChild);
                dfs(it,dupChild,vis);
            }
            else{
                dupNode->neighbors.push_back(vis[it]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* dupNode = new Node(node->val);
        unordered_map<Node*,Node*> vis;
        dfs(node,dupNode,vis);
        return dupNode;
    }
};