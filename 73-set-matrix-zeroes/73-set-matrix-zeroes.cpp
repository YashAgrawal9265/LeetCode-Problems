class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        bool col0 = true;
        int m = mat.size(), n = mat[0].size();
        for(int i=0;i<m;i++){
            if(mat[i][0] == 0) col0 = false;
            for(int j=1;j<n;j++){
                if(mat[i][j] == 0){
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
            
        }
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(mat[0][j] == 0 or mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
            if(col0 == false){
                mat[i][0] = 0;
            }
        }
    }
};