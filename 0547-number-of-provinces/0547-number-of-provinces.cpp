class Solution {
private:
    void solve(vector<vector<int>>& mat, vector<int>& vis, int node, int n){
        vis[node] = 1;
        for(int i=0;i<n;i++){
            if(mat[node][i] == 1 and !vis[i]) solve(mat,vis,i,n);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(isConnected,vis,i,n);
                count++;
            }
        }
        return count;
    }
};