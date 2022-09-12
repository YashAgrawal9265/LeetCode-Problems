class Solution {
public:
    int dp[1005][1005][3];
    // greater = 1 means take greater element;
    int solve(vector<int>& nums, int idx, int prev_idx, int n, int greater){
        if(idx == n) return 0;
        if(dp[idx][prev_idx+1][greater] != -1) return dp[idx][prev_idx+1][greater];
        int notake = solve(nums,idx+1,prev_idx,n,greater);
        int take = 0;
        if(prev_idx == -1){
            take = 1 + solve(nums,idx+1,idx,n,greater);
        }
        else{
            if(greater and nums[idx] > nums[prev_idx]){
                take = 1 + solve(nums,idx+1,idx,n,0);
            }
            else if(greater == 0 and nums[idx] < nums[prev_idx]){
                take = 1 + solve(nums,idx+1,idx,n,1);
            }
        }
        return dp[idx][prev_idx+1][greater] = max(take,notake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return max(solve(nums,0,-1,n,0), solve(nums,0,-1,n,1));
       
    }
};