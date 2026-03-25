class Solution {
public:
    int solve(string str, int idx, int n,vector<int>& dp){
        if(idx == n) return 1;
        if(str[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        temp += str[idx];
        int op1 = solve(str,idx+1,n,dp);
        int op2 = 0;
        if(idx + 1 < n){
            temp += str[idx+1];
            if(stoi(temp) > 26) return dp[idx] = op1;
            op2 = solve(str,idx+2,n,dp);
        }
        return dp[idx] = op1 + op2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};