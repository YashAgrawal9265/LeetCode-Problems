class Solution {
public:
    unordered_set<string> result;
    void solve(string& str, int idx, int n, int open, int close, int balance, string temp){
        if(idx == n){
            if(open == 0 and close == 0 and balance == 0){
                result.insert(temp);
            }
            return;
        }
        if(open < 0 or close < 0 or balance < 0) return;
        if(open + close > n-idx) return;
        if(str[idx] == '('){
            if(open > 0){
                solve(str,idx+1,n,open-1,close,balance,temp);
            }
            solve(str,idx+1,n,open,close,balance+1,temp+'(');
        }
        else if(str[idx] == ')'){
            if(close > 0){
                solve(str,idx+1,n,open,close-1,balance,temp);
            }
            solve(str,idx+1,n,open,close,balance-1,temp+')');
        }
        else{
            solve(str,idx+1,n,open,close,balance,temp+str[idx]);
        }
    }
    vector<string> removeInvalidParentheses(string str) {
        int n = str.size();
        int open = 0, close = 0;
        for(auto it: str){
            if(it == '('){
                open++;
            }
            else if(it == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        solve(str,0,n,open,close,0,"");
        vector<string> v(result.begin(),result.end());
        return v;
    }
};