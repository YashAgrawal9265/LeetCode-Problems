class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            int u = it[0], v= it[1], wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<long long> dist(n,1e18), count(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        dist[0] = 0;
        count[0] = 1;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            long long distance = it.first;
            long long node = it.second;
            for(auto it: adj[node]){
                long long childNode=it.first;
                long long wt = it.second;
                if(distance+wt < dist[childNode]){
                    dist[childNode]=distance+wt;
                    count[childNode] = count[node];
                    pq.push({dist[childNode],childNode});
                }
                else if(distance+wt == dist[childNode]){
                    count[childNode] = (count[childNode]+count[node]) % mod;
                    
                }
            }
        }
        return count[n-1];
    }
};