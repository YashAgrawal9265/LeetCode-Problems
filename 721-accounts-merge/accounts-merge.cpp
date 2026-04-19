class DisjointSet{
private:
    vector<int> parent;
    vector<int> rank;
    vector<long long> size;
public:
    DisjointSet(int n){
        parent.resize(n);
        rank.resize(n,1);
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
    void unionByRank(int x, int y){
        x = findParent(x);
        y = findParent(y);
        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else if(rank[y] > rank[x]){
            parent[x] = y;
            
        }
        else{
            parent[x] = y;
            rank[y]++;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet dt(n);
        
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string word = accounts[i][j];
                if(mp.find(word) == mp.end()){
                    mp[word] = i;
                }
                else{
                    dt.unionByRank(i,mp[word]);
                }
            }
        }
        unordered_map<int,vector<string>> wordMap;
        for(auto it: mp){
            int x = dt.findParent(it.second);
            wordMap[x].push_back(it.first);
        }
        vector<vector<string>> result;
        for(int i=0;i<n;i++){
            if(wordMap[i].size() == 0) continue;
            sort(wordMap[i].begin(),wordMap[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: wordMap[i]) temp.push_back(it);
            result.push_back(temp);
        }
        return result;

    }
};