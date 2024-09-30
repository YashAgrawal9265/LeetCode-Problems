class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e8));
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        queue<pair<int,pair<int,int>>> q;
        dist[0][0] = 0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int node = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                    if(max(dist[x][y],abs(mat[nx][ny] - mat[x][y])) < dist[nx][ny]){
                        dist[nx][ny] = max(dist[x][y],abs(mat[nx][ny] - mat[x][y]));
                        q.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};