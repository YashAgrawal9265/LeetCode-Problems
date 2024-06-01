class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int totOranges = 0;
        int rotOranges = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 0) totOranges++;
                if(grid[i][j] == 2){
                    vis[i][j] = 1;
                    q.push({i,j});
                    rotOranges++;
                }
            }
        }
        if(totOranges == 0) return 0;
        
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + xdir[i];
                    int ny = y + ydir[i];
                    if(nx >= 0 and ny >= 0 and nx < m and ny < n and grid[nx][ny] != 0 and !vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny] = 1;
                        rotOranges++;
                    }
                }
                
            }
            time++;
            
        }
        if(totOranges != rotOranges) return -1;
        return time-1;
       
    }
};