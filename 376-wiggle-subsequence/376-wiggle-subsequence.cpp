class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int prev_greater = 1, prev_smaller = 1;
        int cur_greater, cur_smaller;
        for(int i=1;i<n;i++){
            
            if(nums[i] > nums[i-1]){
                cur_greater = 1 + prev_smaller;
                cur_smaller = prev_smaller;
            }
            else if(nums[i] < nums[i-1]){
                cur_smaller = 1 + prev_greater;
                cur_greater = prev_greater;
            }
            else{
                cur_smaller = prev_smaller;
                cur_greater = prev_greater;
            }
            prev_greater = cur_greater;
            prev_smaller = cur_smaller;
        }
        return max(prev_smaller,prev_greater);
    }
};