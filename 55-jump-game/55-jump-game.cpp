class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx >= nums.size()-1){
            return true;
        }
        if(dp[idx] != -1) return dp[idx];
        bool temp = false;
        for(int i=1;i<=nums[idx];i++){
            temp = temp or solve(nums,idx+i,dp);
            if(temp) break;
        }
        return dp[idx] = temp;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
    }
};