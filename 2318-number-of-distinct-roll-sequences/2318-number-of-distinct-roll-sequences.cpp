class Solution {
public:
    int mod = 1e9 + 7;
    long long solve(int n, int prev, int prev_prev, vector<vector<vector<long long>>>& dp){
        if(n == 0) return 1;
        if(dp[n][prev][prev_prev] != -1) return dp[n][prev][prev_prev];
        long long count = 0;
        for(int i=1;i<=6;i++){
            if(i == prev || i == prev_prev || __gcd(prev,i) != 1) continue;
            count = (count + solve(n-1,i,prev,dp)) % mod;;
        }
        return dp[n][prev][prev_prev] = count;
    }
    int distinctSequences(int n) {
        vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(8,vector<long long>(8,-1)));
        return solve(n,7,7,dp);
    }
};