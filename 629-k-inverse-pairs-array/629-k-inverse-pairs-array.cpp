class Solution {
public:
    int dp[1005][1005];
    int mod = 1e9 + 7;
    int solve(int n, int k){
        if(k < 0) return 0;
        if(n == 0){
            if(k == 0) return 1;
            return 0;
        }
        if(dp[n][k] != -1) return dp[n][k];
        int count = 0;
        for(int i=1;i<=n;i++){
            count = (count + solve(n-1,k-i+1)) % mod;
        }
        return dp[n][k] = count;
    }
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+3,vector<int>(k+3,0));
        dp[0][0] = 1;
        for(int N=1;N<=n;N++){
            for(int K=0;K<=k;K++){
                dp[N][K] = (dp[N-1][K] + (K > 0 ? dp[N][K-1] : 0)) % mod;
                if(K >= N){
                    dp[N][K] = dp[N][K] - dp[N-1][K-N];
                    if(dp[N][K] < 0) dp[N][K] += mod;
                }
            }
        }
        return dp[n][k];
    }
};