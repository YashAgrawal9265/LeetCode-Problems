class Solution {
private:
    int subarraysWithSmallerThanKDistinct(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n = nums.size();
        int l = 0, r= 0, count = 0;
        unordered_map<int,int> mp;
        while(r < n){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithSmallerThanKDistinct(nums,k) - subarraysWithSmallerThanKDistinct(nums,k-1);
    }
};