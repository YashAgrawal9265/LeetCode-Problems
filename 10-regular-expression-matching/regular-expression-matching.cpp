class Solution {
public:
    int dp[100][100];
    bool solve(string s, string p, int i, int j, int m , int n){
        // base conditions
        if(i == m and j==n){
            return 1;
        }
        if(j == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j + 1 < n and p[j+1] == '*'){
            bool op1 = solve(s,p,i,j+2,m,n);
            bool op2 = false;
            if(i < m and (s[i] == p[j] or p[j] == '.')){
                op2 = solve(s,p,i+1,j,m,n);
            }
            return dp[i][j] = op1 or op2;
        }
        bool op1 = false;
        if(i<m and (s[i] == p[j] or p[j] == '.')){
            op1 = solve(s,p,i+1,j+1,m,n);
        }
        return dp[i][j] = op1;

    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,p,0,0,m,n);
    }
};