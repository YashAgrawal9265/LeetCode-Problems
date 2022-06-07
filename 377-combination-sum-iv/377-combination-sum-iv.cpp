class Solution {
public:
    int solve(vector<int>& nums, int target, int n, vector<int>& dp){
        if(target == 0){
            return 1;
        }
        if(dp[target] != -1 ) return dp[target];
        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] <= target){
                count += solve(nums,target-nums[i],n,dp);
            }
        }
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<unsigned> dp(k+1,-1);
        // return solve(nums,k,n,dp);
        dp[0] = 1;
        for(int target=1;target<=k;target++){
            int count = 0;
            for(int i=0;i<n;i++){
                if(nums[i] <= target){
                    count += dp[target-nums[i]];
                }
            }
            dp[target] = count;
        }
        return dp[k];
    }
};