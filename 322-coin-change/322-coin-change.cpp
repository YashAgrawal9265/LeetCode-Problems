class Solution
{
public:
    int solve(vector<int> &coins, int idx, int target, int n,vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            if(target == 0) return 0;
            return 1e9;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int notake = solve(coins, idx + 1, target, n, dp);
        int take = 1e9;
        if (target >= coins[idx])
            take = 1 + solve(coins, idx, target - coins[idx], n, dp);

        return dp[idx][target] = min(notake, take);
    }
    int coinChange(vector<int> &coins, int tar)
    {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(tar + 1, 1e9));
        dp[n][0] = 0;
        for(int idx = n-1;idx>=0;idx--){
            for(int target=0;target<=tar;target++){
                int notake = dp[idx + 1][target];
                int take = 1e9;
                if (target >= coins[idx])
                    take = 1 + dp[idx][target - coins[idx]];

                dp[idx][target] = min(notake, take);
            }
        }
        
        int ans = dp[0][tar];
        return ans >= 1e9 ? -1 : ans;
    }
};