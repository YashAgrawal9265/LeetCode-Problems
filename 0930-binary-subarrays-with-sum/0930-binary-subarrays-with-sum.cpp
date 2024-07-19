class Solution {
private:
    int numSubarraysWithSumSmallerThanK(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, count =0, sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumSmallerThanK(nums,goal) - numSubarraysWithSumSmallerThanK(nums,goal-1);
    }
};