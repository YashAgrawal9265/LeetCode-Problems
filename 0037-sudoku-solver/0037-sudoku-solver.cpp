class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        for(int i=0;i<board.size();i++){
            // checking row;
            if(board[i][col] == c) return false;
            
            // checking col;
            if(board[row][i] == c) return false;
            
            // checking box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};