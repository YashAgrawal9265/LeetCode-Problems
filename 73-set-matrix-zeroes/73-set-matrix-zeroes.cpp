class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>> v;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0) v.push_back({i,j});
            }
        }
        for(auto it: v){
            int x = it.first, y = it.second;
            for(int i=0;i<n;i++) mat[x][i] = 0;
            for(int i=0;i<m;i++) mat[i][y] = 0;
        }
    }
};