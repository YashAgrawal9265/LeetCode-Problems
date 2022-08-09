class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,long long> mp;
        long long goodPair = 0;
        for(int i=0;i<n;i++){
            goodPair += mp[i-nums[i]];
            mp[i-nums[i]]++;
        }
        long long totPair = (1LL*n*(n-1)) / 2;
        return totPair - goodPair;
    }
};