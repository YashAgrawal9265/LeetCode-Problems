class DisjointSet{
private:
    vector<int> rank,parent;
public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string,int> mailNodeMp;
        DisjointSet dt(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailNodeMp.find(mail) == mailNodeMp.end()){
                    mailNodeMp[mail] = i;
                }
                else{
                    dt.unionByRank(mailNodeMp[mail],i);
                }
            }
        }
        
        vector<string> mergeMails[n];
        for(auto it: mailNodeMp){
            int node = dt.findParent(it.second);
            string mail = it.first;
            mergeMails[node].push_back(mail);            
        }
        
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(mergeMails[i].size() == 0) continue;
            sort(mergeMails[i].begin(),mergeMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergeMails[i]) temp.push_back(it);
            result.push_back(temp);
            
        }
        return result;
    }
};