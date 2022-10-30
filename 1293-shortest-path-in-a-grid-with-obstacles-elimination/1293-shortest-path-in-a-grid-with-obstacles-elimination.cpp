struct ele{
    int x,y,steps,k;
    ele(int a, int b, int c, int d){
        x = a;
        y = b;
        steps = c;
        k = d;
    }
};
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        queue<ele> q;
        q.push({0,0,0,k});
        
        vis[0][0][k] = 1;
        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};
        while(!q.empty()){
            auto [x,y,steps,k] = q.front();
            q.pop();
            
            if(x == m-1 and y == n-1) return steps;
            for(int i=0;i<4;i++){
                
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                    
                    if(grid[nx][ny] == 0 and !vis[nx][ny][k]){
                        vis[nx][ny][k] = 1;
                        q.push({nx,ny,steps+1,k});
                    }
                    else if(grid[nx][ny] == 1 and k > 0 and !vis[nx][ny][k-1]){
                        vis[nx][ny][k-1] = 1;
                        q.push({nx,ny,steps+1,k-1});
                    }
                }
            }
        }
        return -1;
    }
};