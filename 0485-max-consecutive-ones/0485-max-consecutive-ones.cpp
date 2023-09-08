class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxi = 0;
        while(right < n){
            if(nums[right] == 1){
                maxi = max(maxi,right-left+1);
            }
            else{
                left = right+1;
            }
            right++;
        }
        return maxi;
    }
};