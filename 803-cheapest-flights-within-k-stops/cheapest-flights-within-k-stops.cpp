class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<pair<int,int>> adj[n];

        for(auto it: flights){
            int u = it[0], v= it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>> pq;
       
        k += 1;
        vector<int> dist(n,1e9);
        dist[src] = 0;
        // // {k,node,distance};
        pq.push({0,{src,0}});

        while(!pq.empty()){
            int node = pq.front().second.first;
            int curDist = pq.front().second.second;
            int stops = pq.front().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int wt = it.second;
                int childNode = it.first;
                if(curDist + wt < dist[childNode] and (stops + 1) <= k){
                    dist[childNode] = curDist + wt;
                    pq.push({stops+1,{childNode,dist[childNode]}});
                }
            }
        }
        // for(auto it: dist) cout<<it<<" ";
        return dist[dst] >= 1e9 ? -1 : dist[dst];

    }
};