class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int colZero = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j == 0 and mat[i][j] == 0){
                    colZero = 0;
                }
                else{
                    if(mat[i][j] == 0){
                        mat[0][j] = 0;
                        mat[i][0] = 0;
                    }
                }
            }
        }
        // for(auto it: mat){
        //     for(auto i: it) cout<<i<<" ";
        //     cout<<endl;
        // }
        for(int i=m-1;i>=1;i--){
            for(int j=n-1;j>=1;j--){
                if(mat[i][0] == 0 or mat[0][j] == 0){
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int j=1;j<n;j++){
            if(mat[0][0] == 0){
                mat[0][j] = 0;
            }
        }
        for(int i=0;i<m;i++){
            if(colZero == 0){
                mat[i][0] = 0;
            }
        }
    }
};