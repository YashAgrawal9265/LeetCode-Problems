class Solution {
public:
    int solve(string s, string p, int i, int j, int m, int n, vector<vector<long>>& dp){
        if(i >= m and j >= n) return 1;
        if(j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = 0;
        if(j+1 < n and p[j+1] == '*'){
            
            if(i < m and (s[i] == p[j] or p[j] == '.'))
                op1 = solve(s,p,i+1,j,m,n,dp);
    
            op1 = op1 or solve(s,p,i,j+2,m,n,dp);
        }
        int op2 = 0;
        if(i < m and (s[i] == p[j] or p[j] == '.')){
            op2 = solve(s,p,i+1,j+1,m,n,dp);
        }
        return dp[i][j] = op1 or op2;
    }
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<long>> dp(m+1,vector<long>(n+1,-1));
        return solve(s,p,0,0,m,n,dp);
    }
};