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
        vector<int> next(tar + 1, 1e9), cur(tar+1,1e9);
        next[0] = 0, cur[0] = 0;
        for(int idx = n-1;idx>=0;idx--){
            for(int target=0;target<=tar;target++){
                int notake = next[target];
                int take = 1e9;
                if (target >= coins[idx])
                    take = 1 + cur[target - coins[idx]];

                cur[target] = min(notake, take);
            }
            next = cur;
        }
        
        int ans = next[tar];
        return ans >= 1e9 ? -1 : ans;
    }
};