class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx >= nums.size()-1){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int mini = 1e8;
        for(int i=1;i<=nums[idx];i++){
            mini = min(mini,1 + solve(nums,idx+i,dp));
        }
        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};