class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int cnt = 0, mxLen = 0;
        while(right < n){
            if(nums[right] == 0) cnt++;
            while(cnt > k){
                if(nums[left] == 0) cnt--;
                left++;
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};