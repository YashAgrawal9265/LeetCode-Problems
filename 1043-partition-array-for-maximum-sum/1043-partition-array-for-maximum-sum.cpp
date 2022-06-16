class Solution {
public:
    int solve(vector<int>& arr, int idx, int k, int n, vector<int>& dp){
        if(idx == n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int mxSum = 0;
        int mxEle = INT_MIN;
        for(int i=idx;i<min(n,idx+k);i++){
            int sum;
            mxEle = max(mxEle,arr[i]);
            sum = mxEle*(i-idx+1) + solve(arr,i+1,k,n,dp);
            mxSum = max(sum,mxSum);
        }
        return dp[idx] = mxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(arr,0,k,n,dp);
    }
};