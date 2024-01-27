class Solution {
private:
    void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& result, int sum, int idx, int n){
        if(sum == target){
            result.push_back(temp);
            return;
        }
        if(idx == n) return;
        if(sum + nums[idx] <= target){
            temp.push_back(nums[idx]);
            solve(nums,target,temp,result,sum+nums[idx],idx,n);
            temp.pop_back();
        }
        solve(nums,target,temp,result,sum,idx+1,n);
}
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        solve(nums,target,temp,result,0,0,nums.size());
        return result;
    }
};