class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int k = 1;
        int row_st = 0, col_st = 0;
        int col_en = n-1, row_en = n-1;
        int dir = 0;
        while(row_st <= row_en and col_st <= col_en){
            
            if(dir == 0){
                for(int col = col_st ; col<=col_en; col++){
                    
                    mat[row_st][col] = k++;
                    
                    
                }
                row_st++;
            }
            else if(dir == 1){
                for(int row=row_st; row<=row_en; row++){
                    mat[row][col_en] = k++;
                    
                }
                col_en--;
            }
            else if(dir == 2){
                for(int col = col_en ; col>=col_st; col--){
                    mat[row_en][col] = k++;
                    
                }
                row_en--;
            }
            else{
                for(int row=row_en; row>=row_st; row--){
                    mat[row][col_st] = k++;
                   
                }
                col_st++;
            }
            dir = (dir + 1) % 4;
        }
       
        return mat;
        
    }
};