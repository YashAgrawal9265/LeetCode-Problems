class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        // x = 1, o = -1
        vector<int> row(3,0), col(3,0);
        int diag = 0, antiDiag = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == 'X'){
                    row[i] += 1;
                    col[j] += 1;
                    if(i == j) diag += 1;
                    if(i + j == 2) antiDiag += 1;
                    xCount++;
                }
                else if(board[i][j] == 'O'){
                    row[i] -= 1;
                    col[j] -= 1;
                    if(i == j) diag -= 1;
                    if(i + j == 2) antiDiag -= 1;
                    oCount++;
                }
            }
        }
        
        bool p1win = false, p2win = false;
        for(int i=0;i<3;i++){
            if(row[i] == 3 or col[i] == 3) p1win = true;
            if(row[i] == -3 or col[i] == -3) p2win = true;
        }
        if(diag == 3 || antiDiag == 3) p1win = true;
        if(diag == -3 || antiDiag == -3) p2win = true;
        if(p1win and p2win) return false; 
        if(p1win and xCount <= oCount) return false;
        if(p2win and oCount < xCount) return false;
       
        if(xCount == oCount+1 || xCount == oCount){
            return true;
        }
        return false;
    }
};