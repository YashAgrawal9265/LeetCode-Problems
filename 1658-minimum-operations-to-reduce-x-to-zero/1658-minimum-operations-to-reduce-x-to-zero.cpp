class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totSum = 0;
        for(auto it: nums) totSum += it;
        int target = totSum - x;
        if(target == 0) return n;
        unordered_map<int,int> mp;
        int sum = 0;
        int mxLen = -1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum == target){
                mxLen = i+1;
                
            }
            if(mp.find(sum - target) != mp.end()){
                mxLen = max(mxLen,i - mp[sum-target]);
            }
            mp[sum] = i;
            
        }
        
        if(mxLen == -1) return -1;
        return n - mxLen;
    }
};