class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        size.resize(n+1,0);
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet dt(n);
        vector<int> result(2);
        for(auto it: edges){
            if(dt.findParent(it[0]) == dt.findParent(it[1])){
                result[0] = it[0];
                result[1] = it[1];
            }
            else{
                dt.unionBySize(it[0],it[1]);
            }
        }
        return result;
    }
};