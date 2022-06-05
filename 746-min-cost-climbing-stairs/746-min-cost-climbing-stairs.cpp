class Solution {
public:
   
    int minCostClimbingStairs(vector<int>& costs) {
        int n = costs.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int idx = n-1;idx>=0;idx--){
            int op1 = costs[idx] + dp[idx+1];
            int op2 = 1e9;
            if(idx + 2 <= n)
                op2 = costs[idx] + dp[idx+2];
            dp[idx]=min(op1,op2);
        }
        return min(dp[0], dp[1]);
    }
};