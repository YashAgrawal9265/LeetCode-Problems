class Solution {
public:
    bool isPali(string& str, int st, int en){
        while(st <= en){
            if(str[st] != str[en]) return false;
            st++;
            en--;
        }
        return true;
    }
    void solve(string str, int idx, int n, vector<string>& temp, vector<vector<string>>& result){
        if(idx >= n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPali(str,idx,i)){
                temp.push_back(str.substr(idx,i-idx+1));
                solve(str,i+1,n,temp,result);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        vector<vector<string>> result;
        vector<string> temp;
        solve(str,0,str.size(),temp,result);
        return result;
    }
};