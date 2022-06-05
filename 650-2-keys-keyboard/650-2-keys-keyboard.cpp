class Solution {
public:
    int solve(int screen, int n, int clipboard, int canCopy, vector<vector<int>>& dp){
        if(screen > n) return 1e9;
        if(screen == n) return 0;
        if(dp[screen][clipboard] != -1) return dp[screen][clipboard];
        int copy = 1e9, paste = 1e9;
        if(clipboard == 0){
            copy = 1 + solve(screen,n,screen,0,dp);
            return dp[screen][clipboard] = min(copy,paste);
        }
        else{
            if(screen != clipboard) copy = 1+ solve(screen,n,screen,0,dp);
            paste = 1 + solve(screen+clipboard,n,clipboard,1,dp);
            return dp[screen][clipboard] = min(copy,paste);
        }
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(1,n,0,1,dp);
    }
};