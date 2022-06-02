class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>> adj[n];
        for(auto it: meetings){
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,0});
        pq.push({0,firstPerson});
        dist[0] = 0;
        dist[firstPerson] = 0;
        vector<int> result;
        
        while(!pq.empty()){
            auto [time,node] = pq.top();
            pq.pop();
            if(dist[node] < time) continue;
            result.push_back(node);
            for(auto [child,wt]: adj[node]){
                if(wt < dist[child] and time <= wt){
                    dist[child] = wt;
                    pq.push({wt,child});
                }
                
            }
        }
        return result;
    }
};