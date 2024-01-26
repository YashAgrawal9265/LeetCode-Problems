class Solution {
private:
    void solve(int open,int close, string str, int idx, int n,vector<string>& result){
        if(idx == 2*n){
            result.push_back(str);
            return;
        }
        
        if(open > close){
            if(open < n) solve(open+1,close,str+'(',idx+1,n,result);
            solve(open,close+1,str+')',idx+1,n,result);
        }
        else{
           if(open < n) solve(open+1,close,str+'(',idx+1,n,result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(0,0,"",0,n,result);
        return result;
    }
};