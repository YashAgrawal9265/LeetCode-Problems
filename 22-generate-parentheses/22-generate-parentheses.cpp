class Solution {
public:
    void solve(int n, int open, int close, string str, vector<string>& result){
        if(open + close == 2*n){
            result.push_back(str);
            return;
        }
        if(open < n) solve(n,open+1,close,str+'(',result);
        if(close < n and close < open) solve(n,open,close+1,str+')',result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int open = 0, close = 0;
        solve(n,open,close,"",result);
        return result;
    }
};