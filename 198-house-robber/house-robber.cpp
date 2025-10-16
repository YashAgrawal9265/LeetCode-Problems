class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp){
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int op1 = nums[idx] + solve(nums,idx-2,dp);

        int op2 = solve(nums,idx-1,dp);
        return  dp[idx] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,0);
        for(int idx=0;idx<n;idx++){
            int op1 = nums[idx], op2 = 0;
            if(idx -2 >= 0) op1 += dp[idx-2];
            if(idx -1 >= 0) op2 = dp[idx-1];
            dp[idx] = max(op1,op2);
        }
        return dp[n-1];
        return solve(nums,n-1,dp);
    }
};