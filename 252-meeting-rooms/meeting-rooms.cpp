class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 0) return true;
        sort(arr.begin(),arr.end());
        int en = arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0] < en) return false;
            en = arr[i][1];
        }
        return true;
    }
};