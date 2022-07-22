class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n+1,0);
        for(int idx=n-1;idx>=0;idx--){
            int score = 0;
            int mxScore = -1e9;
            for(int i=idx;i<idx+3 and i<n;i++){
                score += stoneValue[i];
                mxScore = max(mxScore,score - dp[i+1]);
            }
            dp[idx] = mxScore;
        }
        int aliceScore = dp[0];
        if(aliceScore == 0) return "Tie";
        return aliceScore > 0 ? "Alice" : "Bob";
    }
};