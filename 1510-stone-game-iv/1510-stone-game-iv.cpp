class Solution {
private:
    bool solve(int n, vector<int>& dp){
        if(dp[n] != -1) return dp[n];
        bool ans = false;
        for(int i=1;i*i<=n;i++){
            ans = ans or !solve(n-(i*i),dp);
        }
        return dp[n] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};