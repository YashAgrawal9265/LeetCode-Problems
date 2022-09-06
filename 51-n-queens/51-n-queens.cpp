class Solution {
public:
    void solve(int col,vector<string>& board, vector<vector<string>>& ans, int n, vector<int>&leftrow, vector<int>& upperDiag, vector<int>& lowerDiag ){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row] == 0 and lowerDiag[row+col] == 0 and upperDiag[n-1 + (row - col)] == 0){
                leftrow[row] = 1;
                lowerDiag[row+col] = 1;
                upperDiag[n-1 + (row - col)] = 1;
                board[row][col] = 'Q';
                solve(col+1,board,ans,n,leftrow,upperDiag,lowerDiag);
                leftrow[row] = 0;
                lowerDiag[row+col] = 0;
                upperDiag[n-1 + (row - col)] = 0;
                board[row][col] = '.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<vector<string>> ans;
        vector<int> leftrow(n,0);
        vector<int> upperDiag(2*n - 1,0);
        vector<int> lowerDiag(2*n - 1, 0);
        solve(0,board,ans,n,leftrow,upperDiag,lowerDiag);
        
        return ans;
    }
    
};