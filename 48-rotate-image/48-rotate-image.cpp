class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(auto &it: mat){
            reverse(it.begin(),it.end());
        }
    }
};