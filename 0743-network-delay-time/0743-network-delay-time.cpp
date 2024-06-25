class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            int u = it[0], v= it[1], wt = it[2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> dist(n+1,1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int distance = it.first;
            int node = it.second;
            for(auto it: adj[node]){
                int childNode=it.first;
                int wt = it.second;
               
                if(distance+wt < dist[childNode]){
                    dist[childNode]=distance+wt;
                    pq.push({dist[childNode],childNode});
                }
            }
        }
        int mini = -1;
        for(int i=1;i<=n;i++){
            if(i == src) continue;
            mini = max(mini,dist[i]);
        }
        return mini >= 1e8 ? -1 : mini;
        
    }
};