class Solution {
public:
    int dp[105][105];
    bool solve(string s1, string s2, string s3, int i, int j){
        if(i+j == s3.size()) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        if(i < s1.size() and j < s2.size() and s1[i] == s3[i+j] and s3[i+j] == s2[j]){
            bool op1 = solve(s1,s2,s3,i+1,j);
            bool op2 = solve(s1,s2,s3,i,j+1);
            return dp[i][j] = op1 or op2;
        }
        else if(i < s1.size() and s1[i] == s3[i+j]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j);
        }
        else if(j < s2.size() and s2[j] == s3[i+j]){
            return dp[i][j] = solve(s1,s2,s3,i,j+1);
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,0,0);
    }
};