class Solution {
public:
    int solve(vector<int> &prices, int idx, int buy, int n, vector<vector<vector<int>>> &dp, int transactions)
    {
        if(transactions == 0) return 0;
        if (idx == n)
            return 0;
        if (dp[idx][transactions][buy] != -1)
            return dp[idx][transactions][buy];
        int profit;
        if (buy)
        {
            // buying stock
            int take = -prices[idx] + solve(prices, idx + 1, 0, n, dp,transactions);
            int notake = solve(prices, idx + 1, 1, n, dp,transactions);
            profit = max(take, notake);
        }
        else
        {
            // selling stock
            int take = prices[idx] + solve(prices, idx + 1, 1, n, dp,transactions-1);
            int notake = solve(prices, idx + 1, 0, n, dp,transactions);
            profit = max(take, notake);
        }
        return dp[idx][transactions][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2,-1)));
        return solve(prices, 0, 1, n, dp,2);
    }
};