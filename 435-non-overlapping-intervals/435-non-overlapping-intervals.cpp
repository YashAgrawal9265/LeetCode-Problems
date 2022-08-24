class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int count = 0;
        int endTime = arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0] < endTime){
                count++;
                endTime = min(endTime,arr[i][1]);
            }
            else{
                endTime = arr[i][1];
            }
        }
        return count;
    }
};