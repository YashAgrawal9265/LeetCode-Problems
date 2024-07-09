class DisjointSet{
    private:
        vector<int> parent,size;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1,0);
            for(int i=0;i<=n;i++)parent[i] = i;
        }
        int findParent(int u){
            if(parent[u] == u) return u;
            return parent[u] = findParent(parent[u]);
        }
        void unionBySize(int u, int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
         }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mxRow = 0, mxCol = 0;
        for(auto it: stones){
            mxRow = max(mxRow,it[0]);
            mxCol = max(mxCol,it[1]);
        }
        DisjointSet ds(mxRow+mxCol+1);
        unordered_map<int,int> mp;
        for(auto it: stones){
            int rowNode = it[0];
            int colNode = it[1] + mxRow + 1;
            if(ds.findParent(rowNode) != ds.findParent(colNode)){
                ds.unionBySize(rowNode,colNode);
            }
            mp[rowNode] = 1;
            mp[colNode] = 1;
        }
        
        int components = 0;
        for(auto it: mp){
            if(ds.findParent(it.first) == it.first) components++;
        }
        return stones.size() - components;
        
    }
};