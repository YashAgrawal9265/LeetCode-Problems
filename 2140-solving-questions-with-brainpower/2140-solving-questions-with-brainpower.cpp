class Solution {
public:
    long long solve(vector<vector<int>>& arr, int idx, int n,vector<long long>& dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        long long nopick = solve(arr,idx+1,n,dp);
        long long pick = arr[idx][0] + solve(arr,idx+arr[idx][1]+1,n,dp);
        return dp[idx] = max(nopick,pick);
    }
    long long mostPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<long long> dp(n+1,-1);
        return solve(arr,0,n,dp);
    }
};