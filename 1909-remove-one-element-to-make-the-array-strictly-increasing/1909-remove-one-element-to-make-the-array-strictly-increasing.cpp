class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        bool used = false;
        for(int i=1;i<n;i++){
            if(nums[i] <= prev){
                if(used) return false;
                used = true;
                if(i == 1 || nums[i] > nums[i-2]) prev = nums[i];
                else prev = nums[i-1];
            }
            else{
                prev = nums[i];
            }
        }
        return true;
    }
};