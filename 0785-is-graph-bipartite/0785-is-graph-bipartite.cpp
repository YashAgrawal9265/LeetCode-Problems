class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, vector<int>& color, int curColor, int node){
        vis[node] = 1;
        color[node] = curColor;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(graph,vis,color,!curColor,it)) return true;
            }
            else if(color[it] == color[node]){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(graph,vis,color,0,i)) return false;
            }
        }
        return true;
    }
};