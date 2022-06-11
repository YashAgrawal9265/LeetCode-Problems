class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totSum = 0;
        for(int i=0;i<n;i++){
            totSum += nums[i];
        }
        if(totSum == x) return n;
        int target = totSum - x;
        int right = 0, left = 0;
        int sum = 0;
        int result = -1;
        while(right < n){
            sum += nums[right];
            while(sum > target and left < right){
                sum -= nums[left];
                left++;
            }
            if(sum == target) result = max(result,right-left+1);
            right++;
        }
        if(result == -1) return -1;
        return n - result;
    }
};