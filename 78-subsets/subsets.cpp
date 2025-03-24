class Solution {
public:
    void solve(vector<int>& nums, int idx, int n, vector<vector<int>>& result, vector<int>& temp){
        if(idx == n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,idx+1,n,result,temp);
        temp.pop_back();
        solve(nums,idx+1,n,result,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> result;
        solve(nums,0,n,result,temp);
        return result;
    }
};