class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxJump = 0;
        for(int i=0;i<n;i++){
            if(i > mxJump) return false;
            mxJump = max(mxJump,i + nums[i]);
        }
        return true;
    }
};