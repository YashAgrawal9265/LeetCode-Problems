class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int count = 1e8;
        for(int i=1;i*i <= n; i++){
            if(i*i <= n){
                
                count = min(count,1+solve(n-(i*i),dp));
            }
        }
        return dp[n] = count;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};