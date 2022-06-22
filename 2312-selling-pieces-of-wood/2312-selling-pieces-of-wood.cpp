class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        for(auto it: prices){
            int i = it[0], j = it[1], p = it[2];
            dp[i][j] = p;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                
                // vertical cuts;
                for(int k=0;k<j;k++){
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[i][j-k]);
                }
                
                // horizontal cuts;
                for(int k=0;k<i;k++){
                    dp[i][j] = max(dp[i][j],dp[k][j]+dp[i-k][j]);
                }
            }
        }
        return dp[m][n];
    }
};