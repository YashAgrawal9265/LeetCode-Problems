class Solution {
public:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int totOr = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0) continue;
                totOr++;
                if(mat[i][j] == 2) q.push({i,j});
            }
        }
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            totOr -= size;
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + xdir[i];
                    int ny = y + ydir[i];
                    if(nx >= 0 and ny >= 0 and nx < m and ny < n and mat[nx][ny] == 1){
                        mat[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
            if(q.size()) time++;
        }
        return totOr == 0 ? time : -1;
    }
};