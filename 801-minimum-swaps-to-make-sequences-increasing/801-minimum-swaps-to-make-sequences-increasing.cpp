class Solution {
public:
    int dp[100005][2];
    int solve(vector<int>& nums1, vector<int>& nums2,int idx, int n, int swapped){
        if(idx == n) return 0;
        if(dp[idx][swapped] != -1) return dp[idx][swapped];
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
            noSwap = solve(nums1,nums2,idx+1,n,0);
        }
        if(nums2[idx] > prev1 and nums1[idx] > prev2){
            swap = 1 + solve(nums1,nums2,idx+1,n,1);
        }
        return dp[idx][swapped] = min(swap,noSwap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof(dp));
        
//         vector<vector<int>> dp(n+1,vector<int>(2,-1));
//         dp[n][0] = 0, dp[n][1] = 0;
//         int prev1 = -1, prev2 = -1;
//         for(int idx=n-1;i>=0;i--){
//             for(int swapped = 0; swapped <= 1; swapped++){
                
//             }
//             int swap = 1e8, noSwap = 1e8;
//             if(nums1[idx] > prev1 and nums2[idx] > prev2){
//                 noSwap = solve(nums1,nums2,nums1[idx],nums2[idx],idx+1,n,0);
//             }
//             if(nums2[idx] > prev1 and nums1[idx] > prev2){
//                 swap = 1 + solve(nums1,nums2,nums2[idx],nums1[idx],idx+1,n,1);
//             }
//             dp[idx][swapped] = min(swap,noSwap);
//         }
        return solve(nums1,nums2,0,n,0);
    }
};