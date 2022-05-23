class element{
public:
    int vertex;
    int cost;
    int stops;
    element(int vertex, int cost, int stops){
        this->vertex = vertex;
        this->cost = cost;
        this->stops = stops;
    }
        
};
struct cmp{
    bool operator()(element a, element b){
        return a.cost > b.cost;
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
        priority_queue<element, vector<element>, cmp> pq;
        pq.push(element(src,0,0));
        vector<int> Stops(n,INT_MAX);
        while(!pq.empty()){
            element temp = pq.top();
            pq.pop();
            if(temp.vertex == dst) return temp.cost;
            if(Stops[temp.vertex] < temp.stops) continue;
            Stops[temp.vertex] = temp.stops;
            if(temp.stops > k) continue;
            for(auto it: adj[temp.vertex]){
                int child = it.first;
                int wt = it.second;  
                pq.push(element(child,wt+temp.cost,temp.stops+1)); 
            }
        }
        return -1;
    }
};