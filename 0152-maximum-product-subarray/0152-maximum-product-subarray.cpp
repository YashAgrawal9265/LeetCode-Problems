class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = nums[0], mn = nums[0], result = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i] < 0){
                swap(mx,mn);
            }
            mx = max(nums[i],nums[i]*mx);
            mn = min(nums[i],nums[i]*mn);
            result = max(result,mx);
        }
        return result;
    }
};