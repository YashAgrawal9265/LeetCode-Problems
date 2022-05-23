class Solution {
public:
    void dfs(vector<pair<int,int>> adj[], vector<int>& vis, vector<int>& values, int node, int val, int& mxVal, int mxTime){
        if(mxTime < 0) return;
        // if(node == 3) cout<<mxTime<<" "<<val<<endl;
        if(node == 0){
            // cout<<mxTime<<" "<<val<<endl;
            mxVal = max(val,mxVal);
        }
        for(auto it: adj[node]){
            int time = it.second;
            int child = it.first;
            if(!vis[child]){
                vis[child] = 1;
                dfs(adj,vis,values,child,val+values[child],mxVal,mxTime-time);
                vis[child] = 0;
            }
            else{
                dfs(adj,vis,values,child,val,mxVal,mxTime-time);
            }
        }
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int mxTime) {
        int n = values.size();
        vector<pair<int,int>> adj[n];
        for(auto it: edges){
            int u = it[0], v = it[1], time = it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<int> vis(n,0);
        int mxVal = INT_MIN;
        vis[0] = 1;
        dfs(adj,vis,values,0,values[0],mxVal,mxTime);
        return mxVal;
    }
};