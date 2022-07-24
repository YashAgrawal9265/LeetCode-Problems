class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,0);
        for(int k=1;k<=n;k++){
            bool ans = false;
            for(int i=1;i*i<=k;i++){
                ans = ans or !dp[k-(i*i)];
            }
            dp[k] = ans;
        }
        return dp[n];
    }
};