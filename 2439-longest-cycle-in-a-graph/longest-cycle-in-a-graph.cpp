class Solution {
public:
    void dfs(vector<int> adj[], vector<int>& vis,vector<int>& dfsVis,vector<int>& count, int node, int& result){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                count[it] = 1 + count[node];
                dfs(adj,vis,dfsVis,count,it,result);
            }
            else if(dfsVis[it]){
                result = max(result,count[node] - count[it] + 1);
            }
        }
        dfsVis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> vis(n,0), dfsVis(n,0), count(n,1);
        int result = -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,dfsVis,count,i,result);
            }
        }
        
        return result;
    }
};