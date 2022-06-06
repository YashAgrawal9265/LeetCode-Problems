class Solution {
public:
    vector<vector<bool>> solve(int n, int k, vector<int> &arr)
    {
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        if (arr[0] <= k)
            dp[0][arr[0]] = true;
        for (int idx = 1; idx < n; idx++)
        {
            for (int target = 1; target <= k; target++)
            {
                int notake = dp[idx - 1][target];
                int take = false;
                if (arr[idx] <= target)
                    take = dp[idx - 1][target - arr[idx]];
                dp[idx][target] = notake | take;
            }
        }
        return dp;
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(auto it: stones){
            sum += it;
        }
        vector<vector<bool>> dp = solve(n, sum,stones);
        int result = INT_MAX;
        for(int i=0;i<=sum/2;i++){
            if(dp[n-1][i]){
                int s1 = i;
                int s2 = sum - i;
                result = min(result,abs(s1-s2));
            }
            
        }
        return result;
    }
};