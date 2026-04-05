class Solution {
public:
    int dfs(int cur, int len,vector<int>& vis, vector<vector<int>>& skip){
        if(len < 0) return 0;
        if(len == 0) return 1;
        vis[cur] = 1;
        int count = 0;
        for(int next = 1;next <=9; next++){
            if(!vis[next] and (skip[cur][next] == 0 || vis[skip[cur][next]])){
                count += dfs(next,len-1,vis,skip);
            }
        }
        vis[cur] = 0;
        return count;
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10,vector<int>(10,0));
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[3][9] = skip[9][3] = 6;
        skip[1][7] = skip[7][1] = 4;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = skip[2][8] = skip[8][2] = 5;

        vector<int> vis(10,0);
        int count = 0;
        for(int i=m;i<=n;i++){
            count += 4*dfs(1,i-1,vis,skip);
            count += 4*dfs(2,i-1,vis,skip);
            count += dfs(5,i-1,vis,skip);
        }
        return count;
    }
};