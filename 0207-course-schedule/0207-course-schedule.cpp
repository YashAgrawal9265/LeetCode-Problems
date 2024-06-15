class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) {
        vector<int> indegree(numCourses,0);
        vector<int> adj[numCourses];
        for(auto it: preq){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return cnt == numCourses;
    }
};