class Solution {
public:
    int dp[100005][2];
    int solve(vector<int>& nums1, vector<int>& nums2, int prev1, int prev2, int idx, int n, int swapped){
        if(idx == n) return 0;
        if(dp[idx][swapped] != -1) return dp[idx][swapped];
        int swap = 1e8, noSwap = 1e8;
        if(nums1[idx] > prev1 and nums2[idx] > prev2){
            noSwap = solve(nums1,nums2,nums1[idx],nums2[idx],idx+1,n,0);
        }
        if(nums2[idx] > prev1 and nums1[idx] > prev2){
            swap = 1 + solve(nums1,nums2,nums2[idx],nums1[idx],idx+1,n,1);
        }
        return dp[idx][swapped] = min(swap,noSwap);
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,-1,-1,0,n,0);
    }
};