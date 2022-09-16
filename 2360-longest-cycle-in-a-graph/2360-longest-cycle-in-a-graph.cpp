class Solution {
public:
    int longest_cycle = -1;
    void dfs(vector<int> adj[], vector<int>& vis, vector<int>& dfsVis, vector<int>& dist, int node, int curDist){
        vis[node] = 1;
        dfsVis[node] = 1;
        dist[node] = curDist;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,dfsVis,dist,it,curDist+1);
            }
            else if(dfsVis[it]){
                longest_cycle = max(longest_cycle, dist[node] - dist[it] + 1);
            }
        }
        dfsVis[node] = 0;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<int> vis(n,0), dfsVis(n,0), dist(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,dfsVis,dist,i,0);
            }
        }
        return longest_cycle;
    }
};