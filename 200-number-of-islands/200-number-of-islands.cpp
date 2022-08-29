class Solution {
public:
    int xdir[4]= {-1,0,1,0};
    int ydir[4]= {0,1,0,-1};
    void dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int x, int y, int m, int n){
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >= 0 and nx < m and ny < n and mat[nx][ny] == '1' and !vis[nx][ny]){
                dfs(mat,vis,nx,ny,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == '1' and !vis[i][j]){
                    count++;
                    dfs(mat,vis,i,j,m,n);
                }
            }
        }
        return count;
    }
};