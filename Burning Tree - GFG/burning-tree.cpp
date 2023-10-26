//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void preorder(Node* root, unordered_map<Node*,Node*>& parent, Node*& target, int key){
        if(!root) return;
        if(root->data == key) target = root;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        preorder(root->left,parent,target,key);
        preorder(root->right,parent,target,key);
    }
    int minTime(Node* root, int key) 
    {
        unordered_map<Node*,Node*> parent;
        Node* target;
        preorder(root,parent,target,key);
        unordered_map<Node*,int> vis;
        queue<Node*> q;
        q.push(target);
        vis[target] = 1;
        int Time = 0;
        while(!q.empty()){
            Time++;
            int size = q.size();
            while(size--){
                Node* node = q.front();
                q.pop();
                if(node->left and !vis[node->left]) q.push(node->left), vis[node->left] = 1;
                if(node->right and !vis[node->right]) q.push(node->right), vis[node->right] = 1;
                if(parent[node] and !vis[parent[node]]) q.push(parent[node]), vis[parent[node]] = 1;
                
            }
            
        }
        
        return Time - 1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends