class DisjointSet{
private:
    vector<int> parent,size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    void unionBySize(int x, int y){
        x = findParent(x);
        y = findParent(y);
        if(size[x] > size[y]){
            parent[y] = x;
            size[x] += size[y];
        }
        else{
            parent[x] = y;
            size[y] += size[x];
        }
    }
    int mxComponentSize(){
        int maxi = 0;
        for(int i=0;i<size.size();i++){
            maxi = max(maxi,size[i]);
        }
        return maxi;
    }
};
class ele{
    public:
        int u, v, wt, i;
        ele(int a, int b, int c, int d){
            u = a, v = b, wt = c, i = d;
        }
};
bool cmp(ele& a, ele& b){
    return a.wt < b.wt;
}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<ele> edgeList;
        int idx = 0;
        for(auto it: edges){
            int u = it[0], v=it[1], wt = it[2], i = idx++;
            edgeList.push_back({u,v,wt,i});
        }
        sort(edgeList.begin(),edgeList.end(),cmp);
        DisjointSet dt(n);
        int mnWt = 0;
        for(auto it: edgeList){
            int u = it.u, v= it.v;
            if(dt.findParent(u) != dt.findParent(v)){
                dt.unionBySize(u,v);
                mnWt += it.wt;
            }
        }
        
        vector<vector<int>> result;
        vector<int> critical, pseudo_critical;
        for(auto it: edgeList){
            int u = it.u, v = it.v, wt = it.wt, i = it.i;
            // critical edges
            DisjointSet dt(n);
            int weight = 0;
            for(auto x: edgeList){
                if(i != x.i and dt.findParent(x.u) != dt.findParent(x.v)){
                    dt.unionBySize(x.u, x.v);
                    weight += x.wt;
                }
            }

            if(weight > mnWt || dt.mxComponentSize() != n){
                critical.push_back(i);
                continue;
            }


            // pseduo critical edges
            DisjointSet dt2(n);
            dt2.unionBySize(u,v);
            int weight2 = wt;
            for(auto x: edgeList){
                if(i != x.i and dt2.findParent(x.u) != dt2.findParent(x.v)){
                    dt2.unionBySize(x.u, x.v);
                    weight2 += x.wt;
                }
            }
            
            if(weight2 == mnWt){
                pseudo_critical.push_back(i);
            }
        }
        result.push_back(critical);
        result.push_back(pseudo_critical);
        return result;
    }
};