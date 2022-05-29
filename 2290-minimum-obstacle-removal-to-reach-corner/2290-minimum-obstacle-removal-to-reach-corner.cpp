class Solution {
public:
    int minimumObstacles(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};
        deque<pair<int,pair<int,int>>> dq;
        vector<vector<int>> dist(m, vector<int>(n,INT_MAX));
        dq.push_front({0,{0,0}});
        dist[0][0] = 0;
        while(!dq.empty()){
            int curWt = dq.front().first;
            int x = dq.front().second.first;
            int y = dq.front().second.second;
            dq.pop_front();
            if(x == m-1 and y == n-1) return curWt;
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                    if(curWt + mat[nx][ny] < dist[nx][ny]){
                        dist[nx][ny] = curWt + mat[nx][ny];
                        if(mat[nx][ny] == 1){
                            dq.push_back({dist[nx][ny],{nx,ny}});
                        }
                        else{
                            dq.push_front({dist[nx][ny],{nx,ny}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};