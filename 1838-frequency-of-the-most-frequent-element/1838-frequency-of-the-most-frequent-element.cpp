class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int right = 0, left = 0;
        int result = 0;
        while(right < n){
            while(1LL*(right-left+1)*nums[right] > prefix[right+1] - prefix[left] + k){
                left++;
            }
            result = max(result,right-left+1);
            right++;
        }
        return result;
    }
};