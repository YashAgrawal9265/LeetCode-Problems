class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(nums[l] <= nums[h]){
                return nums[l];
            }
            if(nums[l] <= nums[mid]){
                l = mid+1;
            }
            else{
                h = mid;
            }
        }
        if(nums[l] < nums[h]) return nums[l];
        return nums[h];
    }
};