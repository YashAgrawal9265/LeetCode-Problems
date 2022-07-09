class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxReach = nums[0];
        for(int i=1;i<n;i++){
            if(mxReach < i) return false;
            mxReach = max(mxReach,i + nums[i]);
        }
        return true;
    }
};