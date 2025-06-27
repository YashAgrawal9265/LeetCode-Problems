class Solution {
public:
    void solve(vector<string>& board,vector<vector<string>>& result, int col, int n, vector<int>& rowMap, vector<int>& upperDiagMap, vector<int>& lowerDiagMap){
        if(col == n){
            result.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(!rowMap[i] and !lowerDiagMap[i+col] and !upperDiagMap[(n-1) + (col - i)]){
                rowMap[i] = 1;
                lowerDiagMap[i+col] = 1;
                upperDiagMap[(n-1) + (col-i)] = 1;
                board[i][col] = 'Q';
                solve(board,result,col+1,n,rowMap,upperDiagMap,lowerDiagMap);
                board[i][col] = '.';
                rowMap[i] = 0;
                lowerDiagMap[i+col] = 0;
                upperDiagMap[(n-1) + (col-i)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        vector<string> board(n,str);
        vector<int> rowMap(n,0), upperDiagMap(2*n - 1, 0), lowerDiagMap(2*n - 1, 0);
        vector<vector<string>> result;
        solve(board,result,0,n,rowMap,upperDiagMap,lowerDiagMap);
        return result;
    }
};