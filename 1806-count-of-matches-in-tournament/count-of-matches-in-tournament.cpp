class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        if(n&1){
            return dp[n] = (n-1)/2 + solve((n-1)/2 + 1,dp);
        }
        else return dp[n] = n/2 + solve(n/2,dp);
    }
    int numberOfMatches(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};