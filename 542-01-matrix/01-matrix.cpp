class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e8));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                    dis[i][j] = 0;
                }
            }
        }
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        while(!q.empty()){
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < m and ny < n and 1 + dist < dis[nx][ny]){
                    dis[nx][ny] = 1 + dist;
                    q.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return dis;
    }
};