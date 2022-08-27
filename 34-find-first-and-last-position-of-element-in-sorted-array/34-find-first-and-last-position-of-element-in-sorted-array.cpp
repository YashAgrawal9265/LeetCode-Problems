class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        int st = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(st < n and nums[st] == target) result.push_back(st);
        else result.push_back(-1);
        
        int en = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        en--;
        if(en >= 0 and nums[en] == target) result.push_back(en);
        else result.push_back(-1);
        return result;
    }
};