class Solution {
private:
    void dfs(vector<int> adj[], vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj,vis,it);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // there should be atleast n-1 edges, else you can't connect all vertices
        if(connections.size() < n-1) return -1;
        
        // find the number of components;
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0], v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(adj,vis,i);
            }
        }
        return components == 0 ? -1 : components-1;
    }
};