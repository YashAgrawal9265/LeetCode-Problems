class Solution {
public:
    int mod = 1e9 + 7;
    int dp[55][55][55];
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    int solve(int x, int y , int m, int n, int mooves){
        if(x < 0 or y < 0 or x >= m or y >= n) return 1;
        if(mooves == 0) return 0;
        if(dp[x][y][mooves] != -1) return dp[x][y][mooves];
        int count = 0;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            count = (count + solve(nx,ny,m,n,mooves-1)) % mod;
        }
        return dp[x][y][mooves] = count;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return solve(startRow,startColumn,m,n,maxMove);
    }
};