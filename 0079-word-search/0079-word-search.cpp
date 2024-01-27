class Solution {
public:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
private:
    bool isValid(int x, int y, int m, int n){
        if(x >= 0 and y >= 0 and x < m and y < n) return true;
        return false;
    }
    bool solve(vector<vector<char>>& mat, vector<vector<int>>& vis, string& str, int idx, int x, int y, int m, int n){
        if(idx == str.size()){
            return true;
        }
        
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(isValid(nx,ny,m,n) and mat[nx][ny] == str[idx] and !vis[nx][ny]){
                vis[nx][ny] = 1;
                if(solve(mat,vis,str,idx+1,nx,ny,m,n)) return true;
                vis[nx][ny] = 0;
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& mat, string str) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str[0] == mat[i][j]){
                    vis[i][j] = 1;
                    if(solve(mat,vis,str,1,i,j,m,n)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return  false;
        
    }
};