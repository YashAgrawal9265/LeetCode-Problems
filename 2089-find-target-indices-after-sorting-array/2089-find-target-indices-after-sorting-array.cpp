class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int cntTarget = 0;
        int cntSmall = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == target) cntTarget++;
            if(nums[i] < target) cntSmall++;
        }
        vector<int> result;
        for(int i=cntSmall;i<cntTarget+cntSmall;i++){
            result.push_back(i);
        }
        return result;
    }
};