class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& edges) {
        vector<int> degree(n);
        
        for(auto it: edges){
            int u = it[0], v =it[1];
            degree[u]++;
            degree[v]++;
        }
        sort(degree.begin(),degree.end());
        long long result = 0;
        for(int i=0;i<n;i++){
            result += 1LL*(i+1)*degree[i];
        }
        return result;
        
    }
};