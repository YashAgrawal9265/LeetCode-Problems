class Solution {
public:
    vector<int> findOrder(int course, vector<vector<int>>& preq) {
        vector<int> adj[course];
        vector<int> indegree(course,0);
        for(auto it: preq){
            int u = it[1], v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<course;i++){
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
        if(result.size() != course) return {};
        return result;
    }
};