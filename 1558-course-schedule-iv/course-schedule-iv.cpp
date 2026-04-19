class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = numCourses;
        if(edges.size() == 0) return vector<bool>(n,false);
        vector<int> adj[n];
        vector<int> indegree(n,0);
        
        // for storing prequisite of nodes
        // vector<vector<int>> preq(n, vector<int>(n,0));// unordered_map<int,unordered_set<int>> preq;
        unordered_map<int,unordered_set<int>> preq;
        for(auto it: edges){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
            
        }
        queue<int> q;
    
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                preq[i] = unordered_set<int>();
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child: adj[node]){
                
                indegree[child]--;
                for(auto it: preq[node]){
                    preq[child].insert(it);
                }
                preq[child].insert(node);
                if(indegree[child] == 0){
                    
                    q.push(child);
                }
            }
        }
        
        vector<bool> result;
        
        for(auto it: queries){
            int u = it[0], v = it[1];
            

            if(preq[v].find(u) != preq[v].end()) result.push_back(true);
            else result.push_back(false);
        
        }
        return result;
    }
};