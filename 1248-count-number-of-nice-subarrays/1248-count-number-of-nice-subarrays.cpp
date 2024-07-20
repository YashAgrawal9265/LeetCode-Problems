class Solution {
private:
    int countSubarraysSmallerEqualToKOdd(vector<int>& nums, int k){
        if(k < 0) return 0;
        int n= nums.size();
        int l = 0, r = 0, countOdd = 0, countSubbArr= 0;
        while(r < n){
            if(nums[r]&1) countOdd++;
            while(countOdd > k){
                if(nums[l]&1) countOdd--;
                l++;
            }
            countSubbArr += (r - l + 1);
            r++;
        }
        return countSubbArr;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarraysSmallerEqualToKOdd(nums,k) - countSubarraysSmallerEqualToKOdd(nums,k-1);
    }
};