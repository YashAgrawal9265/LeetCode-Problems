class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int right = 0, left = 0;
        while(right < n){
            mp[nums[right]]++;
            if(right - left + 1 > k + 1){
                mp[nums[left]]--;
                left++;
            }
            if(mp[nums[left]] > 1) return true;
            right++;
        }
        while(left < right){
            if(mp[nums[left]] > 1) return true;
            mp[nums[left]]--;
            left++;
        }
        return false;
    }
};