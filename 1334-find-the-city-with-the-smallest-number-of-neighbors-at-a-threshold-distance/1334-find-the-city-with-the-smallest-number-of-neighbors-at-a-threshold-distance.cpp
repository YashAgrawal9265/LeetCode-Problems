class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj(n,vector<int>(n,1e8));
        for(auto it: edges){
            int u = it[0], v= it[1], wt = it[2];
            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        for(int i=0;i<n;i++) adj[i][i] = 0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++) cout<<adj[i][j]<<" ";
        //     cout<<endl;
        // }
        
        int minCityCnt = n;
        int idx = -1;
        for(int city=0;city<n;city++){
            int count = 0;
            for(int adjCity = 0;adjCity<n;adjCity++){
                if(adj[city][adjCity] <= distanceThreshold) count++;
            }
            if(count <= minCityCnt){
                minCityCnt = count;
                idx = city;
            }
        }
        return idx;
    }
};