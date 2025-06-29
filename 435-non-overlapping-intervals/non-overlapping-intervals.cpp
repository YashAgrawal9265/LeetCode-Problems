class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> temp = arr[0];
        int cnt = 0;
        for(int i=1;i<arr.size();i++){
            if(temp[1] > arr[i][0]){
                temp[1] = min(temp[1],arr[i][1]);
                cnt++;
            }
            else{
                temp = arr[i];
            }
        }
        return cnt;
    }
};