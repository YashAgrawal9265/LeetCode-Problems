class Solution {
public:
    int dp[1005][105][2];
    int solve(vector<int>& arr, int idx, int n, int k, int buy){
        if(idx == n){
            return 0;
        }
        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];
        if(buy){
            int op1 = -1e8;
            if(k > 0){
                op1 = -arr[idx] + solve(arr,idx+1,n,k,0);
            }
            int op2 = solve(arr,idx+1,n,k,1);
            return dp[idx][k][buy] = max(op1,op2);
        }
        else{
            int op1 = arr[idx] + solve(arr,idx+1,n,k-1,1);
            int op2 = solve(arr,idx+1,n,k,0);
            return dp[idx][k][buy] = max(op1,op2);
        }
        
    }
    int maxProfit(int k, vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,arr.size(),k,1);
    }
};