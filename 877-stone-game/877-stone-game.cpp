class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i > j) continue;
                if(i == j){
                    dp[i][j] = piles[i];
                    continue;
                }
                int op1 = piles[i] - dp[i+1][j];
                int op2 = piles[j] - dp[i][j-1];
                dp[i][j] = max(op1,op2);
            }
        }
        int aliceScore = dp[0][n-1];
        return aliceScore > 0;
    }
};