class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int right = 0, left = 0;
        int result = 1;
        long sum = 0;
        while(right < n){
            sum += nums[right];
            while(1LL*nums[right]*(right-left+1) > sum + k){
                sum -= nums[left];
                left++;
            }
            result = max(result,right-left+1);
            right++;
        }
        return result;
    }
};