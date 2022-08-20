class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int idx = 0, n = stations.size();
        int distance = 0;
        pq.push(startFuel);
        int count = -1;
        while(!pq.empty()){
            distance += pq.top();
            pq.pop();
            count++;
            if(distance >= target) return count;
            while(idx < n and stations[idx][0] <= distance) pq.push({stations[idx++][1]});
        }
        return -1;
    }
};