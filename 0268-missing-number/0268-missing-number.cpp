class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totXor = 0;
        for(int i=1;i<=n;i++) totXor ^= i;
        for(auto it: nums) totXor ^= it;
        return totXor;
    }
};