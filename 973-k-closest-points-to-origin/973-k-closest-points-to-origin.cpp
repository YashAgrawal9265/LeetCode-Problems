class Solution {
public:
    long long getDist(int x, int y){
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,pair<int,int>>> pq;
        for(auto &it: points){
            int x = it[0], y = it[1];
            long long dist = getDist(x,y);
            pq.push({dist,{x,y}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            result.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return result;
            
        
    }
};