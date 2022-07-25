class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;
        int startIdx = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(startIdx < n and nums[startIdx] == target){
            result.push_back(startIdx);
        }
        else{
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        int endIdx = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        endIdx--;
        if(endIdx >= 0 and nums[endIdx] == target){
            result.push_back(endIdx);
        }
        else{
            result.push_back(-1);
        }
        return result;
    }
};