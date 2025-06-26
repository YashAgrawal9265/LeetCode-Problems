class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& nums, int idx, int n){
        if(idx == n){
            result.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            solve(result,nums,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        solve(result,nums,0,n);
        return result;
    }
};