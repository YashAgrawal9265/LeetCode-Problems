class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return {-1,-1};
        vector<int> result = {-1,-1};
        int l = 0, h = n-1;
        //  lower bound;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                h = mid;
            }
        }
        if(nums[l] == target){
            result[0] = l;
        }
        else if(nums[h] == target){
            result[0] = h;
        }
        else{
            return result;
        }
        
        h = n-1;
        // upper bound;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(nums[mid] <= target){
                l = mid;
            }
            else{
                h = mid-1;
            }
        }
        if(nums[h] == target){
            result[1] = h;
        }
        else if(nums[l] == target){
            result[1] = l;
        }
        
        return result;
        
        
    }
};