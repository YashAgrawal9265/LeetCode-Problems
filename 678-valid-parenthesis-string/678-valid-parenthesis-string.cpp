class Solution {
public:
    int solve(string& str, int idx, int n, int open,vector<vector<int>>& dp){
        if(open < 0) return false;
        if(idx == n){
            if(open == 0) return true;
            return false;
        }
        if(dp[idx][open] != -1) return dp[idx][open];
        if(str[idx] == '(') return dp[idx][open] = solve(str,idx+1,n,open+1,dp);
        else if(str[idx] == ')') return dp[idx][open] = solve(str,idx+1,n,open-1,dp);
        else{
            int op1 = solve(str,idx+1,n,open+1,dp);
            int op2 = solve(str,idx+1,n,open-1,dp);
            int op3 = solve(str,idx+1,n,open,dp);
            
            return dp[idx][open] = op1 || op2 || op3;
        }
    }
    bool checkValidString(string str) {
        int n= str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        dp[n][0] = 1;
        for(int idx=n-1;idx>=0;idx--){
            for(int open=0;open<n;open++){
                if(str[idx] == '(') dp[idx][open] = dp[idx+1][open+1];
                else if(str[idx] == ')'){
                    if(open - 1 >= 0){
                       dp[idx][open] = dp[idx+1][open-1]; 
                    }
                }
                else{
                    int op1 = dp[idx+1][open+1];
                    int op2 = (open -1 >= 0) ? dp[idx+1][open-1] : 0;
                    int op3 = dp[idx+1][open];

                    dp[idx][open] = op1 || op2 || op3;
                }
            }
        }
        return dp[0][0];
    }
};