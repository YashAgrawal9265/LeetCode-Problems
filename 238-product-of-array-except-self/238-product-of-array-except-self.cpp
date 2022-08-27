class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = nums[0];
        for(int i=1;i<n;i++) result[i] = result[i-1]*nums[i];
        int prod = 1;
        for(int i=n-1;i>0;i--){
            result[i] = result[i-1]*prod;
            prod *= nums[i];
        }
        result[0] = prod;
        return result;
    }
};