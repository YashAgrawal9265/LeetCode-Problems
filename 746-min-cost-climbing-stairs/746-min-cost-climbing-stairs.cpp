class Solution {
public:
    int solve(vector<int>& costs, int idx, int n, vector<int>& dp){
        if(idx == n) return 0;
        if(dp[idx]  != -1) return dp[idx];
        int op1 = costs[idx] + solve(costs,idx+1,n,dp);
        int op2 = 1e9;
        if(idx + 2 <= n)
            op2 = costs[idx] + solve(costs,idx+2,n,dp);
        return dp[idx]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1), dp2(n+1,-1);
        
        return min(solve(cost,0,n,dp), solve(cost,1,n,dp2));
    }
};