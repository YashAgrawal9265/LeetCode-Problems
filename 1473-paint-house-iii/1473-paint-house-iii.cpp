class Solution {
private:
    int solve(vector<int>& houses, vector<vector<int>>& costs, int idx, int prev_color, int target, int m, int n,vector<vector<vector<int>>>& dp){
        // base condition
        if(idx == m){
            if(target == 0) return 0;
            return 1e8;
        }
        if(dp[idx][prev_color][target] != -1) return dp[idx][prev_color][target];
        if(houses[idx] != 0){
            if(houses[idx]-1 == prev_color){
                return dp[idx][prev_color][target] = solve(houses,costs,idx+1,prev_color,target,m,n,dp);
            }
            else{
                if(target <= 0){
                    return dp[idx][prev_color][target] = 1e8;
                }
                else{
                    return dp[idx][prev_color][target] = solve(houses,costs,idx+1,houses[idx]-1,target-1,m,n,dp);
                }
            }
        }
        else{
            int change = 1e8, noChange = 1e8;
            if(target > 0){
                for(int j=0;j<n;j++){
                    if(j == prev_color) continue;
                    change = min(change,costs[idx][j] + solve(houses,costs,idx+1,j,target-1,m,n,dp));     
                }
            }
            if(idx != 0)
                noChange = costs[idx][prev_color] + solve(houses,costs,idx+1,prev_color,target,m,n,dp);
            return dp[idx][prev_color][target] = min(change,noChange);
        }
        return 1e8;
        
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& costs, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int result = solve(houses,costs,0,n,target,m,n,dp);
        return result >= 1e8 ? -1 : result;
    }
};