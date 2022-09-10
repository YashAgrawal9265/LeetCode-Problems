class Solution
{
public:
    pair<int, int> findPos(int cur, int n)
    {
        int r = (cur - 1) / n;
        int c = (cur - 1) % n;

        int row = n - 1 - r;
        int col;
        if (row % 2 == n % 2)
            col = n - 1 - c;
        else
            col = c;

        pair<int, int> p = {row, col};
        return p;
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int,int>> q;
        q.push({1,0});
        vis[n - 1][0] = 1;
        int steps = 0;
        while (!q.empty())
        {
            auto [cur,steps] = q.front();
            q.pop();
            
                
                
                if (cur == n * n)
                    return steps;
                for (int i = 1; i <= 6; i++)
                {
                    if (cur + i > n * n)
                        break;
                    pair<int, int> temp = findPos(cur + i, n);
                    int x = temp.first, y = temp.second;
                    if (!vis[x][y])
                    {
                        vis[x][y] = 1;
                        if (board[x][y] == -1)
                        {
                            q.push({cur + i,steps+1});
                        }
                        else
                        {
                            q.push({board[x][y],steps+1});
                        }
                    }
                }
            
        }
        return -1;
    }
};