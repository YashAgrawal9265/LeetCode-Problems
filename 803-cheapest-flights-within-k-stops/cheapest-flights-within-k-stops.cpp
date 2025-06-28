class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it: flights){
            int u = it[0], v= it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        k++;
        vector<int> dist(n,1e8);
        // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,src}});
        dist[src] = 0;
        while(!pq.empty()){
            int stops = pq.front().first;
            int curDist = pq.front().second.first;
            int node = pq.front().second.second;
            pq.pop();
            for(auto it: adj[node]){
                int childNode= it.first, childWt = it.second;
                if(stops + 1 <= k and curDist + childWt < dist[childNode]){
                    dist[childNode] = curDist + childWt;
                    pq.push({stops+1,{dist[childNode],childNode}});
                }
            }
        }
        return dist[dst] >= 1e8 ? -1 : dist[dst];
    }
};