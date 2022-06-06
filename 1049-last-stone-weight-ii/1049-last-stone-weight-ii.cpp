class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for(auto it: stones){
            sum += it;
        }
        vector<vector<int>> dp(n, vector<int>(sum+1,0));
        dp[0][0] = 1;
        dp[0][stones[0]] = 1;
        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=sum;target++){
                int nopick = dp[idx-1][target];
                int pick = 0;
                if(stones[idx] <= target){
                    pick = dp[idx-1][target-stones[idx]];
                }
                dp[idx][target] = (nopick or pick);
            }
        }
        
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