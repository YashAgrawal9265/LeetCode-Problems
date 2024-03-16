class Solution {
private:
    int solve(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        int pick = 0;
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            pick = 1 + solve(nums,idx+1,idx,dp);
        }
        int nopick = solve(nums,idx+1,prevIdx,dp);
        return dp[idx][prevIdx+1] = max(pick,nopick);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        for(int idx=n;idx>=0;idx--){
            for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
                if(idx == n){
                    dp[idx][prevIdx+1] = 0;
                    continue;
                }
                int pick = 0;
                if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
                    pick = 1 + dp[idx+1][idx+1];
                }
                int nopick = dp[idx+1][prevIdx+1];
                dp[idx][prevIdx+1] = max(pick,nopick);
            }
        }
        return dp[0][-1+1];
        
        
    }
};