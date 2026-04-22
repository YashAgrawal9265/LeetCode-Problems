class Solution {
public:
    int solve(vector<int>& arr, int target, int idx, vector<vector<int>>& dp){
        if(idx < 0){
            if(target == 0) return 1;
            return 0;
        }
        
        if(dp[idx][target] != -1) return dp[idx][target];
        int op1 = solve(arr,target,idx-1,dp);
        int op2 = 0;
        if(arr[idx] <= target){
            op2 = solve(arr,target-arr[idx],idx-1,dp);
        }
        return dp[idx][target] = op1 | op2;
        // return op1 or op2;
    }
    vector<vector<int>> solve2(vector<int>& arr, int k, int n){
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int idx=0;idx<n;idx++){
            for(int target=0;target<=k;target++){
                if(target == 0){
                    dp[idx][target] = 1;
                    continue;
                }
                if(idx-1 < 0) continue;
                
                // cout<<target<<" "<<idx-1<<endl;
                int op1 = dp[idx-1][target];
                int op2 = 0;
                if(arr[idx] <= target){
                    op2 = dp[idx-1][target-arr[idx]];
                }
                dp[idx][target] = op1 | op2;
            }
        }
        return dp;
    }
    int lastStoneWeightII(vector<int>& arr) {
        int n= arr.size();
        int tot = 0;
        for(auto it: arr) tot += it;
        int k = tot;
        

        vector<vector<int>> dp = solve2(arr,tot,n);
        cout<<tot<<endl;
      
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=tot;j++){
        //         cout<<dp[i][j]<<" ";
        //     }cout<<endl;
        // }
        int mini = tot;
        for(int i=0;i<tot;i++){
            if(dp[n-1][i] == 1){
                int s1 = i;
                int s2 = tot - i;
                mini = min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};