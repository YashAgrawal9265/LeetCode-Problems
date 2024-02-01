class Solution {
private:
    bool isValid(string str){
        int open = 0, close = 0;
        for(auto it: str){
            if(it == '(') open++;
            else if(it == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        cout<<open<<" "<<close<<endl;
        if(open + close > 0) return false;
        return true;
    }
    void solve(string& str, unordered_set<string>& result, string temp, int idx, int invalidOpen, int invalidClose){
        
        if(invalidOpen + invalidClose > str.size()-idx) return;
        if(idx == str.size()){
            
            if(isValid(temp)){
                result.insert(temp);
            }
            return;
        }
        
        if(str[idx] == '('){
            if(invalidOpen > 0){
                solve(str,result,temp,idx+1,invalidOpen - 1, invalidClose);                
            }
            solve(str,result,temp+str[idx],idx+1,invalidOpen,invalidClose);
        }
        else if(str[idx] == ')'){
            if(invalidClose > 0){
                solve(str,result,temp,idx+1,invalidOpen, invalidClose-1);
            }
            
            solve(str,result,temp+str[idx],idx+1,invalidOpen,invalidClose);
            
        }
        else{
            solve(str,result,temp+str[idx],idx+1,invalidOpen,invalidClose);
        }
    }
public:
    vector<string> removeInvalidParentheses(string str) {
        int open = 0, close = 0;
        for(auto it: str){
            if(it == '(') open++;
            else if(it == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        unordered_set<string> result;
        // cout<<isValid("(a())()");
        
        solve(str,result,"",0,open,close);
         vector<string> ans(result.begin(),result.end());
        return ans;
    }
};