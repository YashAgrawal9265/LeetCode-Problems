class Solution {
private:
    int rev(int n){
        int result = 0;
        while(n){
            int rem = n % 10;
            result = (result * 10) + rem;
            n /= 10;
        }
        return result;
    }
    int mod = 1e9 + 7;
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long, long long> mp;
        long long count = 0;
        for(int i=0;i<n;i++){
            count = (count + mp[nums[i] - rev(nums[i])]) % mod;
            mp[nums[i] - rev(nums[i])]++;
        }
        return count;
    }
};