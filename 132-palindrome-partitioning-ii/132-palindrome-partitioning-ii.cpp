class Solution {
public:
    int solve(string& str, int i, int n, vector<vector<int>>& pdp, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int mnPart = INT_MAX;
        for(int k=i;k<n;k++){
            int part;
            if(pdp[i][k]){
                part = 1 + solve(str,k+1,n,pdp,dp);
            }
            mnPart = min(mnPart,part);
        }
        return dp[i] = mnPart;
    }
    int minCut(string str) {
        int n = str.size();
        vector<vector<int>> pdp(n, vector<int>(n, 0));
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)
                    pdp[i][j] = 1;
                else if (gap == 1)
                {
                    pdp[i][j] = (str[i] == str[j]);
                }
                else
                {
                    if (str[i] == str[j] and pdp[i + 1][j - 1] == 1)
                        pdp[i][j] = 1;
                    else
                        pdp[i][j] = 0;
                }
            }
        }
        vector<int> dp(n+1,-1);
        return solve(str,0,n,pdp,dp) - 1;
        
    }
};