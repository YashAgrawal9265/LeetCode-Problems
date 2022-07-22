class Solution {
public:
    int solve(vector<int>& stoneValue, int idx, int n,vector<int>& dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int score = 0;
        int mxScore = -1e9;
        for(int i=idx;i<idx+3 and i<n;i++){
            score += stoneValue[i];
            mxScore = max(mxScore,score - solve(stoneValue,i+1,n,dp));
        }
        return dp[idx] = mxScore;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1,-1);
        int aliceScore = solve(stoneValue,0,n,dp);
        if(aliceScore == 0) return "Tie";
        return aliceScore > 0 ? "Alice" : "Bob";
    }
};