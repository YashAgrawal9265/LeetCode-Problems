class Solution {
private:
    void solve(int open, int close, string str, vector<string>& result, int n){
        if(open == n and close == n){
            result.push_back(str);
            return;
        }
        if(open < n)solve(open+1,close,str+'(', result,n);
        if(close < n and open > close)solve(open,close+1,str+')',result,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(0,0,"",result,n);
        return result;
    }
};