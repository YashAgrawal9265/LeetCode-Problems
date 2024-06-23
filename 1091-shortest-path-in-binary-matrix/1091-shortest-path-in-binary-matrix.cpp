class Solution {
public:   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        int n = grid.size();
        int xdir[8] = {-1,-1,0,1,1,1,0,-1};
        int ydir[8] = {0,1,1,1,0,-1,-1,-1};
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] == 0 and dist[x][y] + 1 < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        return dist[n-1][n-1] >= 1e8 ? -1 : dist[n-1][n-1];
        
    }
};