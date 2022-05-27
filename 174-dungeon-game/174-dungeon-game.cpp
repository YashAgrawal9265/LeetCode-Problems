class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> next(n, 0), cur(n,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 and j == n-1){
                    if(mat[i][j] <= 0) cur[j] = abs(mat[i][j]) + 1;
                    else cur[j] = 1;
                }
                else{
                   int down = 1e8;
                    if(i+1 < m)
                        down = next[j];
                    int right = 1e8;
                    if(j+1 < n)
                        right = cur[j+1];
                    int result = mat[i][j] - min(right,down);
                    if(result < 0) result = abs(result);
                    else result = 1;
                    cur[j] = result;  
                }
            }
            next = cur;
        } 
        return next[0];
    }
};