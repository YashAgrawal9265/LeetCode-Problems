class Solution {
public:
    int solve(vector<int>& piles, int i, int j,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return piles[i];
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = piles[i] - solve(piles,i+1,j,dp);
        int op2 = piles[j] - solve(piles,i,j-1,dp);
        return dp[i][j] = max(op1,op2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int aliceScore = solve(piles,0,n-1,dp);
        return aliceScore > 0;
    }
};