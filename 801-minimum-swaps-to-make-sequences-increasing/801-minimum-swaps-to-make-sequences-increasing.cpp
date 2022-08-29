class Solution {
public:
    int dp[100005][2];
    int solve(vector<int>& nums1, vector<int>& nums2, int idx, int n, int swap){
        if(idx == n) return 0;
        if(dp[idx][swap]  != -1) return dp[idx][swap];
        if(swap == 0){
            int op1 = 1e8;
            if(idx - 1 >= 0 and nums1[idx] > nums1[idx-1] and nums2[idx] > nums2[idx-1]){
                op1 = solve(nums1,nums2,idx+1,n,0);
            }
            int op2 = 1e8;
            if(idx-1>=0 and nums2[idx] > nums1[idx-1] and nums1[idx] > nums2[idx-1]) op2 = 1 + solve(nums1,nums2,idx+1,n,1);
            return dp[idx][swap] = min(op1,op2);
            
        }
        else{
            int op1 = 1e8;
            if(idx-1 >= 0 and nums1[idx] > nums2[idx-1] and nums2[idx] > nums1[idx-1]){
               op1 = solve(nums1,nums2,idx+1,n,0);
            }
            int op2 = 1e8;
            
            if(idx -1 >= 0 and nums2[idx] > nums2[idx-1] and nums1[idx] > nums1[idx-1]) op2 = 1 + solve(nums1,nums2,idx+1,n,1);
            return dp[idx][swap] = min(op1,op2);
            
        }
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        memset(dp,-1,sizeof(dp));
        int x = solve(nums1,nums2,1,n,0);
        int y = 1 + solve(nums1,nums2,1,n,1);
        return min(x,y);
    }
};