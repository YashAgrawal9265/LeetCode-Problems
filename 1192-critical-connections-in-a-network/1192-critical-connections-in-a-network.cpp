class Solution {
public:
    int timer = 1;
    vector<vector<int>> bridges;
    void dfs(vector<int> adj[], vector<int>& vis, int in[], int low[], int node, int parent){
        vis[node] = 1;
        in[node] = low[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(adj,vis,in,low,it,node);
                low[node] = min(low[node],low[it]);
                if(low[it] > in[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it: edges){
            int u = it[0], v= it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n,0);
        int in[n], low[n];
        dfs(adj,vis,in,low,0,-1);
        return bridges;
    }
};