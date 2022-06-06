class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int curDistance = startFuel;
        int totalStops = 0;
        int idx = 0;
        priority_queue<int> pq;
        while(curDistance < target){
            while(idx < n and curDistance >= stations[idx][0]){
                pq.push(stations[idx][1]);
                idx++;
            }
            if(pq.empty()) return -1;
            curDistance += pq.top();
            pq.pop();
            totalStops++;
        }
        return totalStops;
    }
};