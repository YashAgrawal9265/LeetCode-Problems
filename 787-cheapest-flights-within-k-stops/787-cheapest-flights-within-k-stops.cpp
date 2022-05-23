class ele{
public:
    int price;
    int node;
    int stops;
    ele(int a, int b, int c){
        price = a;
        node = b;
        stops = c;
    }
};
struct cmp{
    bool operator()(ele a, ele b){
        return a.price > b.price;
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
        vector<int> dist(n,INT_MAX), stop(n,INT_MAX);
        priority_queue<ele,vector<ele>,cmp> pq;
        pq.push(ele(0,src,0));
        dist[src] = 0, stop[src] = 0;
        while(!pq.empty()){
            auto [curDist, curNode, curStop] = pq.top();
            pq.pop();
            if(curNode == dst) return curDist;
            if(curStop > k) continue;
            for(auto [child,wt]: adj[curNode]){
                int nextDist = curDist + wt;
                int nextStop = curStop + 1;
                if(nextDist < dist[child] || nextStop < stop[child]){
                   
                    dist[child] = nextDist;
                    stop[child] = nextStop;
                    pq.push({nextDist,child,nextStop});
                }
                
            }
        }
        return -1;
        
    }
};