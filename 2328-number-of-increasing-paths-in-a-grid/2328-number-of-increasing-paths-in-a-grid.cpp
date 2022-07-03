class Solution {
private:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    int mod = 1e9 + 7;
public:
    long long solve(vector<vector<int>>& grid, int x, int y,int m, int n,vector<vector<int>>& dp){
        if(dp[x][y] != -1)return dp[x][y];
        long long count = 0;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >= 0 and nx < m and ny < n and grid[nx][ny] > grid[x][y]){
                count = (count + (1 + solve(grid,nx,ny,m,n,dp)) % mod) % mod;
            }
        }
        return dp[x][y] = count;
        
    }
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        long long result = 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = (result + 1 + (solve(grid,i,j,m,n,dp))) % mod; 
            }
        }
        return result;
    }
};