class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int m = arr.size(), n = arr[0].size();
        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int totOranges = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j] == 0) continue;
                if(arr[i][j] == 2){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
                totOranges++;
            }
        }
        if(totOranges == 0) return 0;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            totOranges -= size;
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x + xdir[i];
                    int ny = y + ydir[i];
                    if(nx >= 0 and ny >= 0 and nx < m and ny < n  and !vis[nx][ny] and arr[nx][ny] == 1){
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
            
            time++;
        }
        return totOranges > 0 ? -1 :  time - 1;
    }
};