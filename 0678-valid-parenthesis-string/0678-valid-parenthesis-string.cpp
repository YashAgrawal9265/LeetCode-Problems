class Solution {
public:
    bool solve(string& str, int idx, int open, int n,vector<vector<int>>& dp){
        if(open < 0) return false;
        if(dp[idx][open] != -1) return dp[idx][open];
        if(idx == n){
            if(open == 0)return true;
            return false;
        }
        if(str[idx] == '(') return dp[idx][open] = solve(str,idx+1,open+1,n,dp);
        else if(str[idx] == ')'){
            if(open <= 0) return dp[idx][open] = false;
            else return dp[idx][open] = solve(str,idx+1,open-1,n,dp);
            // return solve(str,idx+1,open-1,n);
        }
        else{
            bool assumeOpen = solve(str,idx+1,open+1,n,dp);
            bool assumeEmpty = solve(str,idx+1,open,n,dp);
             bool assumeClose = solve(str,idx+1,open-1,n,dp);
            return dp[idx][open] = assumeOpen or assumeEmpty or assumeClose;
        }
      
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(s,0,0,s.size(),dp);
    }
};