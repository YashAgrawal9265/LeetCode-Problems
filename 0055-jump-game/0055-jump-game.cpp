class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int mxReach = 0;
        for(int i=0;i<n;i++){
            if(i <= mxReach){
                mxReach = max(mxReach,i+nums[i]);
            }
            else return false;
        }
        return mxReach >= n-1;
    }
};