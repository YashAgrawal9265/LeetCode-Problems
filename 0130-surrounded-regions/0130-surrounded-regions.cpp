class Solution {
private:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    void dfs(vector<vector<char>>& mat, vector<vector<int>>& vis, int x, int y, int m, int n){
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >= 0 and nx < m and ny < n and mat[nx][ny] == 'O' and !vis[nx][ny]){
                dfs(mat,vis,nx,ny,m,n);
            }
        }
    }
public:
    void solve(vector<vector<char>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(mat[i][0] == 'O') dfs(mat,vis,i,0,m,n);
            if(mat[i][n-1] == 'O') dfs(mat,vis,i,n-1,m,n);
        }
        for(int j=1;j<n-1;j++){
            if(mat[0][j] == 'O') dfs(mat,vis,0,j,m,n);
            if(mat[m-1][j] == 'O') dfs(mat,vis,m-1,j,m,n);
        }
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]) mat[i][j] = 'X';
            }
        }
    }
};