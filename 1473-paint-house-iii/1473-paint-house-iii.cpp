class Solution {
private:
    int solve(vector<int>& houses, vector<vector<int>>& costs, int idx, int prev_color, int target, int m, int n,vector<vector<vector<int>>>& dp){
        if(target < 0) return 1e8;
        if(idx == m){
            if(target == 0) return 0;
            return 1e8;
        }
        if(dp[idx][prev_color][target] != -1) return dp[idx][prev_color][target];
        if(houses[idx] != 0){
            if(houses[idx] == prev_color){
                return dp[idx][prev_color][target] = solve(houses,costs,idx+1,prev_color,target,m,n,dp);
            }
            else{
                return dp[idx][prev_color][target] = solve(houses,costs,idx+1,houses[idx],target-1,m,n,dp);
            }
        }
        else{
            int change = 1e8;
            for(int j=1;j<=n;j++){
                if(j == prev_color){
                    change = min(change,costs[idx][prev_color-1] + solve(houses,costs,idx+1,prev_color,target,m,n,dp));
                }
                else
                    change = min(change,costs[idx][j-1] + solve(houses,costs,idx+1,j,target-1,m,n,dp));     
            }
            
            return dp[idx][prev_color][target] = change;
        }
        
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& costs, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int result = solve(houses,costs,0,0,target,m,n,dp);
        return result >= 1e8 ? -1 : result;
    }
};