class Solution {
public:
    int solve(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = solve(triangle,i+1,j,n,dp);
        int op2 = 1e8;
        if(j+1 <= i+1){
            op2 = solve(triangle,i+1,j+1,n,dp);
        }
        return dp[i][j] = triangle[i][j] + min(op1,op2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(triangle,0,0,n,dp);
    }
};