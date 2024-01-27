class Solution {
private:
    void solve(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& result, int idx){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(i > idx and nums[i] == nums[i-1]) continue;
            if(target < nums[i]) break;
            
            temp.push_back(nums[i]);
            solve(nums,target-nums[i],temp,result,i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> result;
        solve(nums,target,temp,result,0);
        return result;
    }
};