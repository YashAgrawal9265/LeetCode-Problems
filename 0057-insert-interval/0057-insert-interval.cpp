class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<int> temp = newInterval;
        vector<vector<int>> result;
        // insertion for left side;
        int i=0;
        while(i<n and temp[0] > intervals[i][1]){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i<n and temp[1] >= intervals[i][0]){
            temp[0] = min(temp[0],intervals[i][0]);
            temp[1] = max(temp[1],intervals[i][1]);
            i++;
        }
        result.push_back(temp);
        
        // insertion for right side;
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};