class Solution {
public:
    vector<int> topoSort(vector<int> adj[], int n){
        vector<int> indegree(n+1,0);
        for(int i=1;i<=n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
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
        if(result.size() == n) return result;
        return {};
        
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> adj1[k+1], adj2[k+1];
        for(auto it: rowConditions){
            int u = it[0], v= it[1];
            adj1[u].push_back(v);
        }
        for(auto it: colConditions){
            int u = it[0], v= it[1];
            adj2[u].push_back(v);
        }

        vector<int> rowTopo = topoSort(adj1,k);
        unordered_map<int,int> mp;
        
        vector<int> colTopo = topoSort(adj2,k);
        if(rowTopo.size() == 0 || colTopo.size() == 0) return {};
        for(int i=0;i<rowTopo.size();i++) mp[rowTopo[i]] = i;
        vector<vector<int>> result(k,vector<int>(k,0));
        for(int i=0;i<colTopo.size();i++){
            int row = mp[colTopo[i]], col = i;
            result[row][col] = colTopo[i];
        }
        return result;
    }
};