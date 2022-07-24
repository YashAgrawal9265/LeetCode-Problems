class Solution {
private:
    int dp[505][505];
public:
    int solve(vector<int>& arr, int i, int j, vector<int>& prefix){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mxValue = 0;
        for(int k=i;k<j;k++){
            int left = prefix[k] - (i > 0 ? prefix[i-1] : 0);
            int right = prefix[j]-prefix[k];
            if(left < right){
               mxValue = max(mxValue,left + solve(arr,i,k,prefix));
            }
            else if(right < left){
                mxValue = max(mxValue,right + solve(arr,k+1,j,prefix));
            }
            else{
                int l = solve(arr,i,k,prefix);
                int r = solve(arr,k+1,j,prefix);
                mxValue = max(mxValue,left + max(l,r));
            }
        }
        return dp[i][j] = mxValue;
    }
    int stoneGameV(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        vector<int> prefix(n,0);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
            prefix[i] = arr[i] + prefix[i-1];
        }
        return solve(arr,0,n-1,prefix);
    }
};