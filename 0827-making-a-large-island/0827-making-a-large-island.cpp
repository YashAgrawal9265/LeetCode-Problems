class DisjointSet{
private:
    vector<int> size,parent;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getSize(int u){
        int ulp_u = findParent(u);
        return size[ulp_u];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet dt(n*n);
        int xdir[] = {-1,0,1,0};
        int ydir[] = {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int x = i, y = j;
                    for(int k=0;k<4;k++){
                        int nx = x + xdir[k];
                        int ny = y + ydir[k];
                        if(nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] == 1){
                            int node = x*n + y;
                            int adjNode = nx*n + ny;
                            dt.unionBySize(node,adjNode);
                        }
                    }
                }
            }
        }
        int mxArea = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    int x = i, y = j;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int nx = x + xdir[k];
                        int ny = y + ydir[k];
                        if(nx >= 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] == 1){
                            int adjNode = nx*n + ny;
                            st.insert(dt.findParent(adjNode));
                        }
                    }
                    int area = 1;
                    for(auto it: st){
                        area += dt.getSize(it);
                    }
                    mxArea = max(mxArea,area);
                }
            }
        }
        return mxArea == -1 ? n*n : mxArea;
        
    }
};