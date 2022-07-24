class Solution {
private:
    int dp[100005];
    bool solve(int n){
        if(dp[n] != -1) return dp[n];
        bool ans = false;
        for(int i=1;i*i<=n;i++){
            ans = ans or !solve(n-(i*i));
        }
        return dp[n] = ans;
    }
public:
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};