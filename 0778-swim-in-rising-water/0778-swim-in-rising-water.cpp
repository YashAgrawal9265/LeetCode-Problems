class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int distance = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == n-1 and y == n-1) return distance;
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < n and ny < n){
                    if(dist[nx][ny] > max(distance,grid[nx][ny])){
                        dist[nx][ny] = max(distance,grid[nx][ny]);
                        pq.push({dist[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return -1;
    }
};