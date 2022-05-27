class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        int result = 0;
        for(int i=0;i<m;i++){
            dp[i][0] = mat[i][0] - '0';
            result = max(result,dp[i][0]);
        }
        for(int i=0;i<n;i++){
            dp[0][i] = mat[0][i] - '0';
            result = max(result,dp[0][i]);
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j] - '0' == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                    result = max(result,dp[i][j]*dp[i][j]);
                }
            }
            
        }
        
        return result;
    }
};