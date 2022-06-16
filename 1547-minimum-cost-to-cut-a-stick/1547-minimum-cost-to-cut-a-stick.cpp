class Solution {
public:
    int solve(vector<int>& cuts, int i, int j,vector<vector<int>>& dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mnCost = INT_MAX;
        for(int k=i;k<=j;k++){
            int left = solve(cuts,i,k-1,dp);
            int right = solve(cuts,k+1,j,dp);
            int cost = cuts[j+1] - cuts[i-1];
            mnCost = min(mnCost,left+right+cost);
        }
        return dp[i][j] = mnCost;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);    
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m,-1));
        return solve(cuts,1,cuts.size()-2,dp);
    }
};