class Solution {
public:
    bool solve(string s1, string s2, string s3, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m and j == n) return true;
        bool flag1 = false, flag2 = false;
        if(dp[i][j] != -1) return dp[i][j];
        if(i < m and s1[i] == s3[i+j]){
            flag1 = solve(s1,s2,s3,i+1,j,m,n,dp);
        }
        if(j < n and s2[j] == s3[i+j]){
            flag2 = solve(s1,s2,s3,i,j+1,m,n,dp);
        }
        return dp[i][j] = flag1 or flag2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m + n != s3.size()) return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,s3,0,0,m,n,dp);
    }
};