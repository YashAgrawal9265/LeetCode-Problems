class Solution {
public:
    void solve(int open, int close, int n, string& str, vector<string>& result){
        
        if(open == n and close == n){
            result.push_back(str);
            return;
        }
        if(open == 0){
            str += '(';
            solve(open+1,close,n,str,result);
            str.pop_back();
        }
        else{
            if(open < n){
                str += '(';
                solve(open+1,close,n,str,result);
                str.pop_back();
            }
            if(close < open){
                str += ')';
                solve(open,close+1,n,str,result);
                str.pop_back();
            }
            
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str = "";
        solve(0,0,n,str,result);
        return result;
    }
};