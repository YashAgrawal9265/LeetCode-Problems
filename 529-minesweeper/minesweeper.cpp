class Solution {

public:
    int xdir[8] = {-1,-1,0,1,1,1,0,-1};
    int ydir[8] = {0,1,1,1,0,-1,-1,-1};
    void dfs(vector<vector<char>>& board, int x, int y, int m, int n){
        int mineCount = 0;
        int unRevealed = 0;
        for(int i=0;i<8;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            // no adjacent mine;
            if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                if(board[nx][ny] == 'M') mineCount++;
            }
        }
        if(mineCount > 0) board[x][y] = mineCount + '0';
        else{
            board[x][y] = 'B';
            for(int i=0;i<8;i++){
                int nx = x + xdir[i];
                int ny = y + ydir[i];
                // no adjacent mine;
                if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                    if(board[nx][ny] == 'E') dfs(board,nx,ny,m,n);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int m = board.size(), n = board[0].size();
        dfs(board,click[0],click[1],m,n);
        return board;

    }
};