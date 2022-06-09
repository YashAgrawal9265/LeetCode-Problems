class Solution {
public:
    int solve(string& str, int idx, int n, int open,vector<vector<int>>& dp){
        if(open < 0) return false;
        if(dp[idx][open] != -1) return dp[idx][open];
        if(idx == n){
            if(open == 0) return true;
            return false;
        }
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
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(str,0,n,0,dp);
    }
};