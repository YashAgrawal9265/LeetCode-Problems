class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(nums[l] < nums[mid]){
                if(target >= nums[l] and target <= nums[mid]){
                    h = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] and target <= nums[h]){
                    l = mid;
                }
                else{
                    h = mid - 1;
                }
            }
            
        }
        if(nums[l] == target) return l;
        if(nums[h] == target) return h;
        return -1;
    }
};