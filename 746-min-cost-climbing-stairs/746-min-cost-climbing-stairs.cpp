class Solution {
private:
    int dp[1005];
public:
    int solve(vector<int>& arr, int idx, int n){
        if(idx > n) return 1e8;
        if(dp[idx] != -1) return dp[idx]; 
        if(idx == n){
            return 0;
        }
        return dp[idx] = arr[idx] + min(solve(arr,idx+1, n),solve(arr,idx+2,n));
    }
    int minCostClimbingStairs(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        int x = solve(arr,0,n);
        int y = solve(arr,1,n);
        return min(x,y);
    }
};