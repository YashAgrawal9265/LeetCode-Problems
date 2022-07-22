class Solution {
public:
    int dp[105][105][2];
    int solve(vector<int>& piles, int idx, int M, int turn, int n){
        if(idx >= n) return 0;
        
        if(dp[idx][M][turn] != -1) return dp[idx][M][turn];
        // turn 0 = alice turn
        // turn 1 = bob turn
        int sum = 0;
        int mxScore;
        
        if(turn == 0) mxScore = 0;
        else mxScore = 1e9;
        
        for(int i=0;i<2*M and idx+i<n; i++){
            if(turn == 0){
                sum += piles[idx+i];
                mxScore = max(mxScore, sum + solve(piles,idx+i+1,max(i+1,M),1,n));
            }
            else{
                mxScore = min(mxScore,solve(piles,idx+i+1,max(i+1,M),0,n));
            }
        }
        return dp[idx][M][turn] = mxScore;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,1,0,n);
    }
};