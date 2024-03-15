class Solution
{
public:
    int solve(vector<int> &prices, int n, int idx, int buy, vector<vector<int>> &dp)
    {
        if (idx >= n)
            return 0;
        if (dp[idx][buy] != -1)
            return dp[idx][buy];
        int profit;
        if (buy)
        {
            int take = -prices[idx] + solve(prices, n, idx + 1, 0, dp);
            int notake = solve(prices, n, idx + 1, 1, dp);
            profit = max(take, notake);
        }
        else
        {
            int take = prices[idx] + solve(prices, n, idx + 2, 1, dp);
            int notake = solve(prices, n, idx + 1, 0, dp);
            profit = max(take, notake);
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(prices, n, 0, 1, dp);
    }
};