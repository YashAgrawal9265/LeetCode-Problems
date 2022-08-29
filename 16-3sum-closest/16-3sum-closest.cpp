class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int minDiff = INT_MAX, result;
        for(int i=0;i<n-2;i++){
            int left = i + 1, right = n-1;
            int k = target - nums[i];
            while(left < right){
                int x = nums[i] + nums[left] + nums[right];
                
                if(abs(target-x) < minDiff){
                    minDiff = abs(target-x);
                    result = x;
                }
                if(nums[left] + nums[right] < k){
                    left++;
                }
                else if(nums[left] + nums[right] > k){
                    right--;
                }
                else{
                    return target;
                }
            }
        }
        return result;
    }
};