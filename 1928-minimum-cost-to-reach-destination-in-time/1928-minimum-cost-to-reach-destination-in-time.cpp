class ele{
public:
    int cost;
    int node;
    int time;
    ele(int a, int b, int c){
        cost = a;
        node = b;
        time = c;
    }
};
struct cmp{
    bool operator()(ele a, ele b){
        return a.cost > b.cost;
    }
};
class Solution {
public:
    int minCost(int mxTime, vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        for(auto it: edges){
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<ele,vector<ele>,cmp> pq;
        vector<int> dist(n,INT_MAX);
        vector<int> time(n,INT_MAX);
        dist[0] = values[0], time[0] = 0;
        pq.push(ele(dist[0],0,0));
        while(!pq.empty()){
            auto [curDist,curNode,curTime] = pq.top();
            pq.pop();
            if(curNode == n-1 and curTime <= mxTime) return curDist;
            if(curTime > mxTime) continue;
            for(auto [child,wt]: adj[curNode]){
                int nextDist = curDist + values[child];
                int nextTime = curTime + wt;
                if(nextDist < dist[child] || nextTime < time[child]){
                    dist[child] = nextDist;
                    time[child] = nextTime;
                    pq.push({dist[child],child,time[child]});
                }
            }
        }
        return -1;
        
    }
};