class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int  n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];
        while(!pq.empty()){
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < n and ny < n){
                    int mxDist = max(distance,grid[nx][ny]);
                    if(mxDist < dist[nx][ny]){
                        dist[nx][ny] = mxDist;
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return dist[n-1][n-1];
    }
};