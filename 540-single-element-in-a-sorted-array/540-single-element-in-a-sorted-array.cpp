class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n-1;
        while(h-l > 1){
            int mid = (l + h) >> 1;
            if(mid&1 and nums[mid] == nums[mid-1]){
                l = mid + 1;
            }
            else if(!(mid&1) and nums[mid] == nums[mid+1]){
                l = mid + 2;
            }
            else{
                h = mid;
            }
        }
        if(!(l & 1)) return nums[l];
        return nums[h];
    }
};