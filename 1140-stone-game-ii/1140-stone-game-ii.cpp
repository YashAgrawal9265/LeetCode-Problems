class Solution {
public:
    int dp[105][105];
    int solve(vector<int>& piles, int idx, int M, int n){
        if(idx >= n) return 0;
        if(dp[idx][M] != -1) return dp[idx][M];
        int sum = 0;
        int score = -1e8;
        for(int i=0;i<2*M and idx+i<n;i++){
            sum += piles[idx+i];
            score = max(score,sum - solve(piles,idx+i+1,max(i+1,M),n));
        }
        return dp[idx][M] = score;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int n = piles.size();
        int scoreDiff = solve(piles,0,1,n);
        int totScore = 0;
        for(auto it: piles) totScore += it;
        return (scoreDiff + totScore) / 2;
    }
};