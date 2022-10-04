class Solution {
public:
    int dp[105];
    int solve(string& str, int idx, int n){
        if(idx == n) return 1;
        if(str[idx] == '0') return 0; 
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        temp += str[idx];
        if(idx + 1 < n and str[idx+1] == '0'){
            temp += str[idx+1];
            if(stoi(temp) > 26) return dp[idx] = 0;
            return dp[idx] = solve(str,idx+2,n);
        }
        int op1 = solve(str,idx+1,n);
        int op2 = 0;
        if(idx + 1 < n){
            temp += str[idx+1];
            if(stoi(temp) <= 26) op2 = solve(str,idx+2,n);
        }
        return dp[idx] = op1 + op2;
        
    }
    int numDecodings(string str) {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.size());
    }
};