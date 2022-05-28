class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        
        for(auto it: edges){
            int u = it[0], v =it[1];
            degree[u]++;
            degree[v]++;
        }
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({degree[i],i});
        }
        sort(temp.begin(),temp.end());
        vector<int> values(n);
        int val = 1;
        for(auto it: temp){
            values[it.second] = val++;
        }
        long long result = 0;
        for(auto it: edges){
            int u = it[0], v= it[1];
            result += values[u];
            result += values[v];
        }
        return result;
        
    }
};