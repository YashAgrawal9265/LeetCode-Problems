class Solution {
public:
    int count_at_most_k_distinct_integers(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        int right = 0, left = 0;
        int count = 0;
        int result = 0;
        while(right < n){
            mp[nums[right]]++;
            if(mp[nums[right]] == 1) count++;
            while(count > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) count--;
                left++;
            }
            result += (right-left+1);
            right++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return count_at_most_k_distinct_integers(nums,k) - count_at_most_k_distinct_integers(nums,k-1);
    }
};