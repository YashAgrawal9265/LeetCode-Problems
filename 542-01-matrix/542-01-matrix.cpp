struct ele{
    int distance;
    int x;
    int y;
};
class Solution {
public:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n,1e8));
        queue<ele> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({0,i,j});
                    dist[i][j] = 0;
                    
                }
            }
        }
        
        while(!q.empty()){
            auto [distance,x,y] = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                int curDist = distance + 1;
                if(nx >= 0 and ny >= 0 and nx < m and ny < n and curDist < dist[nx][ny]){
                    dist[nx][ny] = curDist;
                    q.push({curDist,nx,ny});
                }
            }
        }
        return dist;
    }
};