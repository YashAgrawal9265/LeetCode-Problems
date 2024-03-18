class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> hash(n);
        vector<int> dp(n,1);
        int mxLen = 0, mxIdx = -1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i] % nums[prev] == 0 and dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
                
            }
            if(dp[i] > mxLen){
                mxIdx = i;
                mxLen = dp[i];
            }
        }
        
        vector<int> result(mxLen);
        // cout<<mxLen<<endl;
        for(int i=mxLen-1;i>=0;i--){
            // cout<<i<<" "<<mxIdx<<endl;
            result[i] = nums[mxIdx];
            mxIdx = hash[mxIdx];
        }
        return result;
    }
};