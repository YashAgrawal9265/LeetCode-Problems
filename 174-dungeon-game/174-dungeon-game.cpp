class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j,int m, int n, vector<vector<int>>& dp){
        if(i == m-1 and j == n-1){
            if(mat[i][j] <= 0) return abs(mat[i][j]) + 1;
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int down = 1e8;
        if(i+1 < m)
            down = solve(mat,i+1,j,m,n,dp);
        int right = 1e8;
        if(j+1 < n)
            right = solve(mat,i,j+1,m,n,dp);
        int result = mat[i][j] - min(right,down);
        if(result < 0) result = abs(result);
        else result = 1;
        return dp[i][j] = result;               
    }
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(mat,0,0,m,n,dp);
    }
};