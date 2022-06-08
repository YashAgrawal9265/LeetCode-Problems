class Solution {
public:
    int solve(vector<int> adj[], int node, vector<int>& quiet,vector<int>& ans){
        if(ans[node] != -1) return ans[node];
        ans[node] = node;
        for(auto it: adj[node]){   
            int mnNode = solve(adj,it,quiet,ans);
            if(quiet[ans[node]] > quiet[mnNode]){
                ans[node] = mnNode;
            } 
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> adj[n];
        for(auto it: richer){
            int u =it[0], v = it[1];
            adj[v].push_back(u);
        }
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            if(ans[i] == -1){
                solve(adj,i,quiet,ans);
            }
        }
        return ans;
    }
};