struct ele{
    int stops,node,distance;
    ele(int stops, int node, int distance){
        this->node = node;
        this->distance = distance;
        this->stops = stops;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
    
        vector<int> dist(n,1e8);
        queue<ele> q;
        q.push({0,src,0});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().node;
            int distance = q.front().distance;
            int stops = q.front().stops;
            q.pop();
            if(stops > k) continue;
            for(auto it: adj[node]){
                int childNode = it.first;
                int wt = it.second;
                if(distance + wt < dist[childNode] and stops <= k){
                    dist[childNode] = distance + wt;
                    q.push({stops+1,childNode,dist[childNode]});
                    
                }
            }
            
        }
        return dist[dst] >= 1e8 ? -1 : dist[dst];
    }
};