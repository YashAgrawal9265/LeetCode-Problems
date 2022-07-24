class Solution {
public:
    int dp[1002][1002];
    int solve(vector<int>& arr, int i, int j, int sum){
        if(i == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int op1 = (sum - arr[i]) - solve(arr,i+1,j,sum-arr[i]);
        int op2 = (sum - arr[j]) - solve(arr,i,j-1,sum-arr[j]);
        return dp[i][j] = max(op1,op2);
    }
    int stoneGameVII(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int n = arr.size();
        int sum = 0;
        for(auto it: arr) sum += it;
        return solve(arr,0,n-1,sum);
    }
};