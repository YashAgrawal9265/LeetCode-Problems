class Solution {
public:
    void dfs(vector<vector<int>>& mat, int node, vector<int>& vis){
        vis[node] = 1;
        for(int child = 0; child < mat.size(); child++){
            if(mat[node][child] == 1 and !vis[child]){
                dfs(mat,child,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> vis(n,0);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(mat,i,vis);
                count++;
            }
        }
        return count;
    }
};