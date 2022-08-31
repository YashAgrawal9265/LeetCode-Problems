class Solution {
private:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    void dfs(vector<vector<int>>& mat, vector<vector<int>>& paVis, vector<vector<int>>& atVis, int x, int y, int m, int n, vector<vector<int>>& result, bool isPacific){
        if(isPacific){
            paVis[x][y] = 1;
        }
        else{
            atVis[x][y] = 1;
        }
        if(paVis[x][y] and atVis[x][y]) result.push_back({x,y});
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >= 0 and nx < m and ny < n and mat[nx][ny] >= mat[x][y]){
                if(isPacific){
                    if(!paVis[nx][ny]) dfs(mat,paVis,atVis,nx,ny,m,n,result,true);
                }
                else{
                    if(!atVis[nx][ny]) dfs(mat,paVis,atVis,nx,ny,m,n,result,false);
                }
            }
        }
            
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> paVis(m, vector<int>(n,0));
        vector<vector<int>> atVis(m,vector<int>(n,0));
        
        vector<vector<int>> result;
        // pacific Ocean
        for(int i=0;i<m;i++){
            if(!paVis[i][0])
                dfs(mat,paVis,atVis,i,0,m,n,result,true);
        }
        for(int j=0;j<n;j++){
            if(!paVis[0][j])
                dfs(mat,paVis,atVis,0,j,m,n,result,true);
        }
        
        // Atlantic Ocean
        for(int i=0;i<m;i++){
            if(!atVis[i][n-1])
                dfs(mat,paVis,atVis,i,n-1,m,n,result,false);
        }
        for(int j=0;j<n;j++){
            if(!atVis[m-1][j])
                dfs(mat,paVis,atVis,m-1,j,m,n,result,false);
        }
        
        return result;
    }
};