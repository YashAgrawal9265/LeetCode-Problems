class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, int m, int n,vector<vector<int>>& dp){
        if(i == m-1){
            if(grid[i][j] == 1) return 0;
            else return -1;
        }
        if(grid[i][j] == 0) return -1;
        if(dp[i][j] != -1) return dp[i][j];
        if(grid[i+1][j] == 0) return dp[i][j] = 0;
        int left = -1;
        if(j-1 >= 0) left = solve(grid,i+1,j-1,m,n,dp);
        int right = -1;
        if(j+1 < n ) right = solve(grid,i+1,j+1,m,n,dp);
        return dp[i][j] = 1 + min(left,right);
        
    }
    int countPyramids(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int result = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]) result += solve(mat,i,j,m,n,dp);
            }
        }
        reverse(mat.begin(),mat.end());
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]) result += solve(mat,i,j,m,n,dp);
            }
        }
        return result;
    }
};