class DisjointSet{
private:
    vector<int> parent,size;
public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i] = i;
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
private:
    void dfs(vector<int> adj[], vector<int>&vis, int node){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(adj,vis,it);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // there should be atleast n-1 edges, else you can't connect all vertices
        if(connections.size() < n-1) return -1;
        
        // find the number of components;
        
        DisjointSet dt(n);
        for(auto it: connections){
            if(dt.findParent(it[0]) != dt.findParent(it[1]))
                dt.unionBySize(it[0],it[1]);
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(dt.findParent(i));
        }
        return st.size() - 1;
         
    }
};