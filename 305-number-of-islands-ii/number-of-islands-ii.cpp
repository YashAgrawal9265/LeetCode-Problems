class DisjointSet{
    private:
        vector<int> parent, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1,0);
            size.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int x){
            if(parent[x] == x) return x;
            return parent[x] = findParent(parent[x]);
        }
        void unionBySize(int u, int v){
            u = findParent(u);
            v = findParent(v);
            if(size[u] > size[v]){
                parent[v] = u;
                size[u] += size[v];
            }
            else{
                parent[u] = v;
                size[v] += size[u];
            }
        }
};
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& arr) {
        DisjointSet dt(m*n);
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        int cnt = 0;
        vector<int> result;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(auto it: arr){
            int x = it[0];
            int y = it[1];
            
            if(vis[x][y] == 1){
                result.push_back(cnt);
                continue;
            }
            cnt += 1;
            for(int i=0;i<4;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                
                if(nx >= 0 and ny >= 0 and nx < m and ny < n and vis[nx][ny] == 1 ){
                    
                    int adjNode = (nx*n + ny);
                    int node = (x*n + y);
                    if(dt.findParent(adjNode) != dt.findParent(node)){
                        cnt--;
                        dt.unionBySize(adjNode,node);
                    }
                }
            }
            vis[x][y] = 1;
            result.push_back(cnt);
        }
        return result;
    }
};