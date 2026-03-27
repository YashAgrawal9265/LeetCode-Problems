class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        int i = 1;
        sort(arr.begin(),arr.end());
        vector<int> temp = arr[0];
        int cnt = 0;
        while(i < n){
            if(arr[i][0] < temp[1]){
                temp[1] = min(arr[i][1],temp[1]);
                cnt++;
            }
            else{
                temp = arr[i];
            }
            i++;
        }
        return cnt;
    }
};