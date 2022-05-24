class DisjointSet{
private:
    vector<long long> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(size[u] < size[v]){
            parent[u] = v;
            size[v] += size[u];
        }
        else{
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        
        DisjointSet st(n);
        vector<bool> result;
        for(auto &it: requests){
            int u = it[0], v = it[1];
            u = st.findParent(u);
            v = st.findParent(v);
            bool flag = true;
            for(auto &it: restrictions){
                int x = st.findParent(it[0]);
                int y = st.findParent(it[1]);
                if((u == x and v == y) || (u == y and v == x)){
                    result.push_back(false);
                    flag = false;
                    break;
                }
            }
            if(flag){
                result.push_back(true);
                st.Union(u,v);
            }
        }
        return result;
    }
};