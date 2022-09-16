class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums,vector<int>& mult, int l, int idx, int n){
        if(idx == mult.size()){
            return 0;
        }
        if(dp[l][idx] != INT_MIN) return dp[l][idx];
        int r = n - 1 - (idx-l);
        int op1 = nums[l]*mult[idx] + solve(nums,mult,l+1,idx+1,n);
        int op2 = nums[r]*mult[idx] + solve(nums,mult,l,idx+1,n);
        return dp[l][idx] = max(op1,op2);
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size(), m = mult.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solve(nums,mult,0,0,nums.size());
    }
};