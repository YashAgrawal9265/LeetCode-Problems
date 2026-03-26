class Solution {
public:
    int solve(string str, int idx, unordered_set<string>& st, int n, vector<int>& dp){
        if(idx == n) return 1;
        if(dp[idx] != -1) return dp[idx];
        string temp = "";
        int result = 0;
        for(int i=idx;i<n;i++){
            temp += str[i];
            if(st.find(temp) != st.end()) result = result | solve(str,i+1,st,n,dp);
        }
        return dp[idx] = result;
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n = str.size();
        vector<int> dp(n+1,-1);
        return solve(str,0,st,n,dp);
        
    }
};