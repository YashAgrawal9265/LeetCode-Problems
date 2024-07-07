class Solution {
private:
    void dijkstra(vector<pair<int,int>> adj[],int src, vector<int>& mp, int distanceThreshold,int n){
        vector<int> dist(n,1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            int node = pq.top().second;
            int distanec = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int wt = it.second;
                int childNode = it.first;
                if(dist[node] + wt < dist[childNode]){
                    dist[childNode] = dist[node] + wt;
                    pq.push({dist[childNode],childNode});
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(i != src and dist[i] <= distanceThreshold){
                mp[src]++;
            }
        }
        
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        for(auto it: edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int> mp(n,n);
        
        for(int i=0;i<n;i++){
            dijkstra(adj,i,mp,distanceThreshold,n);
        }
        int miniNumCity = mp[0];
        int idx = 0;
        // for(int i=0;i<n;i++) cout<<mp[i]<<" ";
        for(int i=1;i<n;i++){
            if(mp[i] <= miniNumCity){
                miniNumCity = mp[i];
                idx = i;
            }
        }
        return idx;
    }
};