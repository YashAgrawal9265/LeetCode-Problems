class Solution {
public:
    int solve(string& s1, string& s2, int i, int j,vector<vector<int>>& dp){
        if(i < 0 or j < 0){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(s1,s2,i-1,j-1,dp);
        }
        else{
            return dp[i][j] = max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp)); 
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // for(int i=0;i<m;i++){
        //     for(int j=n;j>=0;j--){
        //         if(i == m or j == n){
        //             dp[i][j] = 0;
        //             continue;
        //         }
        //         if(s1[i] == s2[j]){
        //             dp[i][j] = 1 + dp[i+1][j+1];
        //         }
        //         else{
        //             dp[i][j] = max(dp[i+1][j],dp[i][j+1]); 
        //         }
        //     }
        // }
        return solve(s1,s2,m-1,n-1,dp);
        // return dp[0][0];
    }
};