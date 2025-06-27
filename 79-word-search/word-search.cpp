class Solution {
public:
    int xdir[4] = {-1,0,1,0};
    int ydir[4] = {0,1,0,-1};
    bool solve(vector<vector<char>>& board, string& word, int idx, int x, int y, int n, vector<vector<int>>& vis){
        if(idx == n){
            return true;
        }
       
        
        for(int i=0;i<4;i++){
            int nx = x + xdir[i];
            int ny = y + ydir[i];
            if(nx >= 0 and ny >= 0 and nx < board.size() and ny < board[0].size() and board[nx][ny] == word[idx] and !vis[nx][ny]){
                vis[nx][ny] = 1;
                if(solve(board,word,idx+1,nx,ny,n,vis)) return true;
                vis[nx][ny] = 0;
            }
        }
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int idx = 0;
        int m = board.size(), n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(solve(board,word,1,i,j,word.size(), vis)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};