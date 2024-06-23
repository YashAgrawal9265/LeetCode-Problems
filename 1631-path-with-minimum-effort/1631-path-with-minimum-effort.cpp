struct ele{
   int x,y,wt;
    ele(int a, int b, int c){
        x = a;
        y = b;
        wt = c;
    }
};
struct cmp{
    bool operator()(ele a, ele b){
        return a.wt > b.wt;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int xdir[4] = {-1,0,1,0};
        int ydir[4] = {0,1,0,-1};
        
        vector<vector<int>> dist(m,vector<int>(n,1e8));
        priority_queue<ele,vector<ele>,cmp> pq;
        dist[0][0] = 0;
        pq.push(ele(0,0,0));
        while(!pq.empty()){
            int x = pq.top().x;
            int y = pq.top().y;
            int wt = pq.top().wt;
            pq.pop();
            if(x == m-1 and y == n-1) return wt;
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                    int mxDiff = max(dist[x][y],abs(heights[x][y]-heights[nx][ny]));
                    if(mxDiff < dist[nx][ny]){
                        dist[nx][ny] = mxDiff;
                        pq.push(ele(nx,ny,mxDiff));
                    }
                }
                
                
            }
        }
        
        return -1;
    }
};