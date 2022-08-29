class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0] = 0, dp[n][1] = 0;
        
        for(int idx=n-1;idx>=0;idx--){
            for(int swapped = 0; swapped <= 1; swapped++){
                int prev1 = -1;
                int prev2 = -1;
                if(idx > 0){
                    prev1 = nums1[idx-1];
                    prev2 = nums2[idx-1];
                }
                if(swapped)
                    swap(prev1, prev2);

                int noSwap = 1e8, swap = 1e8;
                if(nums1[idx] > prev1 and nums2[idx] > prev2){
                    noSwap = dp[idx+1][0];
                }
                if(nums2[idx] > prev1 and nums1[idx] > prev2){
                    swap = 1 + dp[idx+1][1];
                }
                dp[idx][swapped] = min(swap,noSwap);
            }
            
        }
        return dp[0][0];
    }
};