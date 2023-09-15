class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0 ,high = n-1;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        if(nums[low] < nums[high]) return nums[low];
        return nums[high];
    }
};