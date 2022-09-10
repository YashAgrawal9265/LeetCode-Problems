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
    int coinChange(vector<int> &coins, int target)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ans = solve(coins, 0, target,n, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};