class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int st = 0;
        while(st + 1 < n and nums[st] <= nums[st+1]) st++;
        
        if(st == n-1) return 0;
        
        int en = n-1;
        while(en-1 >= 0 and nums[en] >= nums[en-1]) en--;
        
        int mini = 1e8, maxi = -1e8;
        for(int i=st;i<=en;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        
        while(st-1 >= 0 and nums[st-1] > mini) st--;
        while(en+1 < n and nums[en+1] < maxi) en++;
        
        return en - st + 1;
    }
};