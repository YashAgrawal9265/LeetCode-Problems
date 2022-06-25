class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        for(int i=0;i<n - 1;i++){
            if(nums[i] > nums[i+1] and !flag){
                if(i - 1 >= 0){
                    if(nums[i-1] <= nums[i+1]){
                        nums[i] = nums[i+1];
                    }
                    else{
                        nums[i+1] = nums[i];
                    }
                }
                else{
                    nums[i] = nums[i+1];
                }
                flag = true;
            }
            else if(nums[i] > nums[i+1] and flag) return false;
        }
        return true;
    }
};