class Solution {
private:
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k,vector<vector<int>>& dp){
        if(k == 0) return 1;
        if(i == 0 and j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int result = 0;
        if(i-1 >= 0 and j-1 >= 0 and s3[k-1] == s2[j-1] and s3[k-1] == s1[i-1]){
            result = solve(s1,s2,s3,i-1,j,k-1,dp) or solve(s1,s2,s3,i,j-1,k-1,dp);
        }
        else if(j-1 >= 0 and s3[k-1] == s2[j-1]){
            result = solve(s1,s2,s3,i,j-1,k-1,dp);
        }
        else if(i-1 >= 0 and s3[k-1] == s1[i-1]){
            result = solve(s1,s2,s3,i-1,j,k-1,dp);
        }
        return dp[i][j] = result;
        
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size(), b = s2.size(), c = s3.size(); 
        if(a + b  != c) return false;
        vector<vector<int>> dp(a+1,vector<int>(b+1,-1));
        // vector<vector<vector<int>>> dp(a+1,vector<vector<int>>(b+1,vector<int>(c+1,-1)));
        return solve(s1,s2,s3,a,b,c,dp);
    }
};