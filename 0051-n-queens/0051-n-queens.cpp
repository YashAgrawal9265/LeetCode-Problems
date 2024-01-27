class Solution {
private:
    bool isSafe(vector<string>& board, int row, int col, int n){
        // checking left side;
        for(int i=col;i>=0;i--){
            if(board[row][i] == 'Q') return false;
        }
        
        // checking lower diagonal;
        int i = row, j = col;
        while(i < n and j >= 0){
            if(board[i][j] == 'Q') return false;
            i++,j--;
        }
        
        // checking upper diagonal;
        i = row, j = col;
        while(i >= 0 and j >= 0){
            if(board[i][j] == 'Q') return false;
            i--,j--;
        }
        return true;
    }
    void solve(vector<vector<string>>& result,vector<string>& board, int col,int n){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(board,i,col,n)){
                board[i][col] = 'Q';
                solve(result,board,col+1,n);
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string> board(n,str);
        vector<vector<string>> result;
        solve(result,board,0,n);
        return result;
    }
};