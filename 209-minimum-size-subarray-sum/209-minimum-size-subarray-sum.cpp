class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0, mnLen=INT_MAX;
        while(right < n){
            sum += nums[right];
            while(sum >= target){
                mnLen = min(mnLen,right-left+1);
                sum -= nums[left];
                left++;
            }
            
            right++;
        }
        return mnLen == INT_MAX ? 0 : mnLen;
    }
};