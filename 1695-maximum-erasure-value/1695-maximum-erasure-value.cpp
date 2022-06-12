class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        unordered_map<int,int> mp;
        long long result = 0;
        long long sum = 0;
        while(right < n){
            mp[nums[right]]++;
            sum += nums[right];
            while(mp[nums[right]] > 1){
                sum -= nums[left];
                mp[nums[left]]--;
                left++;
            }
            result = max(result,sum);
            right++;
        }
        return result;
    }
};