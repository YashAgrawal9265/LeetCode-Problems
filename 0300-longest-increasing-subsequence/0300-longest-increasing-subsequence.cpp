class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int mxLen = 1;
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[prev] < nums[i] and dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                }
            }
            mxLen = max(mxLen,dp[i]);
        }
       
        return mxLen;
    }
};