class Solution {
private:
    void dfs(vector<int> adj[], int node, int parent, vector<int>& in, vector<int>& low, int& timer, vector<int>& vis, vector<vector<int>>& result){
        vis[node] = 1;
        timer++;
        in[node] = timer;
        low[node] = timer;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,it,node,in,low,timer,vis,result);
                low[node] = min(low[node],low[it]);
                if(low[it] > in[node]){
                    result.push_back({node,it});
                }
            }
            else if(vis[it] and it != parent){
                low[node] = min(low[node],low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> result;
        vector<int> in(n,0), low(n,0), vis(n,0);
        int timer = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,-1,in,low, timer, vis,result);
            }
        }
        return result;
    }
};