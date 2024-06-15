class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> indegree(n);
        
        
        // reversing the nodes
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                int u = graph[i][j], v = i;
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};