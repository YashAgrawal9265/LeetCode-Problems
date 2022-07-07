class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) {
        long  mini = lower;
        long maxi = lower;
        long x = lower;
        for(int i=0;i<arr.size();i++){
            x += arr[i];
            mini = min(x,mini);
            maxi = max(x,maxi);
        }
        long ans = upper - lower - (maxi - mini) + 1;
        if(ans < 0) ans = 0;
        return ans;
    }
};