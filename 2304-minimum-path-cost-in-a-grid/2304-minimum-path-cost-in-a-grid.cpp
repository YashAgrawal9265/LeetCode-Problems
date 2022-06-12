class Solution {
public:
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> next(n,0), cur(n,0);
        for(int j=0;j<n;j++) next[j] = grid[m-1][j];
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mini = 1e8;
                if(i + 1 <= m-1){
                    
                    for(int k=0;k<n;k++){
                        mini = min(mini, moveCost[grid[i][j]][k] + grid[i][j] + next[k]);
                    }
                }
                cur[j] = mini;
            }
            next = cur;
        }
        int result = 1e8;
        for(int j=0;j<n;j++){
            result = min(result,next[j]);
        }
        return result;
        
    }
};