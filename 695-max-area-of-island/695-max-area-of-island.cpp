class Solution {
public:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    int solve(vector<vector<int>>& mat, vector<vector<int>>& vis, int x, int y, int m, int n){
        vis[x][y] = 1;
        int count = 0;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >=0 and nx < m and ny < n and mat[nx][ny] and !vis[nx][ny]){
                count += (1 + solve(mat,vis,nx,ny,m,n));
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        int mxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] and !vis[i][j]){
                    mxArea = max(mxArea, 1 + solve(mat,vis,i,j,m,n));
                }
            }
        }
        return mxArea;
    }
};