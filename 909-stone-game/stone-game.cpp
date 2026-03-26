class Solution {
public:
    // turn = 0 = alice turn
    // turn = 1 = bob turn
    int solve(vector<int>& arr, int i, int j, int turn, vector<vector<int>>& dp){
        if(i > j){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(turn == 0){
            int op1 = arr[i] + solve(arr,i+1,j,!turn,dp);
            int op2 = arr[j] + solve(arr,i,j-1,!turn,dp);
            return dp[i][j] = max(op1,op2);
        }
        else{
            int op1 = -arr[i] + solve(arr,i+1,j,!turn,dp);
            int op2 = -arr[j] + solve(arr,i,j-1,!turn,dp);
            return dp[i][j] = min(op1,op2);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        if(solve(piles,0,n-1,0,dp) > 0) return true;
        return false;
    }
};