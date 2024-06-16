class Solution {
public:
    bool checkCycle(vector<vector<int>>& graph, vector<int>& vis, vector<int>& dfsVis, vector<int>& check, int node){
        vis[node] = 1;
        dfsVis[node] = 1;
        for(auto it: graph[node]){
            if(!vis[it]){
                if(checkCycle(graph,vis,dfsVis,check,it)) return true;
            }
            else if(dfsVis[it]) return true;
        }
        dfsVis[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0), dfsVis(v,0), check(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                checkCycle(graph,vis,dfsVis,check,i);
            }
        }
        vector<int> result;
        for(int i=0;i<v;i++){
            if(check[i] == 1) result.push_back(i);
        }
        return result;
    }
};