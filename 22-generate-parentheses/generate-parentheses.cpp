class Solution {
public:
    void solve(int open, int close, int n, string str, vector<string>& result){
        
        if(open == n and close == n){
            result.push_back(str);
            return;
        }
        if(open == 0){
            solve(open+1,close,n,str+'(',result);
        }
        else{
            if(open < n) solve(open+1,close,n,str+'(',result);
            if(close < open) solve(open,close+1,n,str+')',result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(0,0,n,"",result);
        return result;
    }
};