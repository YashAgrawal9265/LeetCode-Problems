class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n+1,0), suffix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i];
        }
        if(suffix[0] == target) return n;
        int left = 0 , right = 0;
        int windowSize = -1;
        while(right < n){
           
            int sum = prefix[left] + suffix[right+1];
            while(sum < target and left < right){
                left++;
                sum = prefix[left] + suffix[right+1];
            }
            if(sum == target){
                windowSize = max(windowSize,right-left+1);
            }
            right++;
        }
        
        if(windowSize == -1) return -1;
        return n - windowSize;
        
    }
};