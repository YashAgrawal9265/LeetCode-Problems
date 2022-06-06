class Solution {
public:
    int solve(vector<int>& days, int idx, int n, vector<int>& cost, vector<int>& dp){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int next_idx;
        next_idx = upper_bound(days.begin(),days.end(),days[idx]) - days.begin();
        int oneDayPass = cost[0] + solve(days,next_idx,n,cost,dp);
        
        next_idx = upper_bound(days.begin(),days.end(),days[idx] + 6) - days.begin();
        int sevenDayPass = cost[1] + solve(days,next_idx,n,cost,dp);
        
        next_idx = upper_bound(days.begin(),days.end(),days[idx] + 29) - days.begin();
        int thirtyDayPass = cost[2] + solve(days,next_idx,n,cost,dp);
        
        return dp[idx] = min(oneDayPass, min(sevenDayPass, thirtyDayPass));

    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n = days.size();
        vector<int> dp(n+1,-1);
        return solve(days,0,n,cost,dp);
    }
};