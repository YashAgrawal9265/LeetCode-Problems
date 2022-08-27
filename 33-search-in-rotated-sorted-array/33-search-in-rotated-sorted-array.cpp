class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(high-low > 1){
            int mid = (low + high) >> 1;
            if(nums[low] < nums[mid]){
                if(target >= nums[low] and target <= nums[mid]){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] and target <= nums[high]){
                    low = mid;
                }
                else{
                    high = mid-1;
                }
            }
        }
        if(nums[low] == target) return low;
        if(nums[high] == target) return high;
        return -1;
    }
};