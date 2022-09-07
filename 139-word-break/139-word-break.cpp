class Solution {
public:
    unordered_set<string> st;
    int dp[305];
    int solve(string& str, int idx, int n){
        if(idx >= n) return true;
        if(dp[idx] != -1) return dp[idx];
        for(int i=idx;i<n;i++){
            if(st.find(str.substr(idx,i-idx+1)) != st.end()){
                if(solve(str,i+1,n)) return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string str, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for(auto it: wordDict) st.insert(it);
        return solve(str,0,str.size());
    }
};