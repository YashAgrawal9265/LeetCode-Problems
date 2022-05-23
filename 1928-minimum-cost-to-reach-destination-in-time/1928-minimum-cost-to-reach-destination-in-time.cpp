class ele{
public:
    int val;
    int node;
    int time;
    ele(int a, int b, int c){
        val = a;
        node = b;
        time = c;
    }
};
struct cmp{
    bool operator()(ele a, ele b){
        return a.val > b.val;
    }
};
class Solution {
public:
    int dfs(vector<pair<int,int>> adj[], vector<int>& vis, vector<int>& values, int node, int mxTime, vector<vector<int>>& dp){
        if(mxTime < 0) return 1e8;
        if(node == values.size()-1){
            return values[values.size()-1];
        }
        if(dp[node][mxTime] != -1) return dp[node][mxTime];
        // vis[node] = 1;
        int mnVal = 1e8;
        for(auto it: adj[node]){
            int child = it.first, time = it.second;
            // if(!vis[child]){
                // vis[node] = 1;
                mnVal = min(mnVal, values[node] + dfs(adj,vis,values,child,mxTime-time,dp)); 
                // vis[node] = 0;
            // }
           
        }
        // vis[node] = 0;
        return dp[node][mxTime] = mnVal;
    }
    int minCost(int mxTime, vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        for(auto it: edges){
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<int> vis(n,0);
        vector<vector<int>> dp(n, vector<int>(mxTime+1,-1));
        int result = dfs(adj,vis,values,0,mxTime,dp);
        return result >= 1e8 ? -1 : result; 
        vector<int> dist(n,INT_MAX);
        dist[0] = values[0];
        priority_queue<ele, vector<ele>, cmp> pq;
        pq.push(ele(values[0],0,mxTime));
        while(!pq.empty()){
            int node = pq.top().node;
            int time = pq.top().time;
            int val = pq.top().val;
            pq.pop();
            if(dist[node] < val) continue;
            if(node == n-1) return val;
            for(auto it: adj[node]){
                int child = it.first, t = it.second;
                if(time - t >= 0 and dist[node] + values[child] < dist[child]){
                    dist[child] = dist[node] + values[child];
                    pq.push(ele(dist[child],child,time-t));
                }
            }
            
        }
        return -1;
    }
};