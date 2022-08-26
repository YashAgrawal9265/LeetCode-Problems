class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = 1;
        while(j < n){
            if(nums[i-1] == nums[j]){
                j++;
            }
            else{
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};