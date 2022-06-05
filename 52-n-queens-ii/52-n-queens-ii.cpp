class Solution {
public:
    bool isSafe(vector<vector<int>>& mat, int i, int j, int n){
        if(i < 0  or j < 0 or i >= n or j >= n) return false;
        
        // checking on left side
        for(int col=0;col<=j;col++){
            if(mat[i][col] == 1) return false;
        }
        
        // checking upper diagonal
        for(int row=i,col=j;row >= 0 and col >=0; row--,col--){
            if(mat[row][col] == 1) return false;
        }
        
        // checking lower diagonal
        for(int row=i,col=j;row < n and col >=0; row++,col--){
            if(mat[row][col] == 1) return false;
        }
        return true;
    }
    
    void solve(vector<vector<int>>& mat, int j, int& count, int n){
        if(j == n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(mat,i,j,n)){
                mat[i][j] = 1;
                solve(mat,j+1,count,n);
                mat[i][j] = 0;
            }
        }
        
        
    }
    int totalNQueens(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int count = 0;
        solve(mat,0,count,n);
        return count;
    }
};