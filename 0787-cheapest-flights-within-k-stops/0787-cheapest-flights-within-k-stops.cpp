class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u = it[0], v= it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,1e8);
        queue<pair<int,pair<int,int>>> pq;
        
        pq.push({0,{0,src}});
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.front().second.second;
            int distance = pq.front().second.first;
            int stops = pq.front().first;
            pq.pop();
            for(auto it: adj[node]){
                int childNode = it.first;
                int childWt = it.second;
                if(distance + childWt < dist[childNode] and stops <= k){
                    dist[childNode] = distance + childWt;
                    pq.push({stops+1,{dist[childNode],childNode}});
                }
            }
        }
        return dist[dst] >= 1e8 ? -1 : dist[dst];
    }
};