class Solution {
public:
    bool isPali(string& str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        return true;
    }
    void solve(string& str, int idx, int n, vector<vector<string>>& result, vector<string>& temp){
        if(idx == n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPali(str,idx,i)){
                temp.push_back(str.substr(idx,i-idx+1));
                solve(str,i+1,n,result,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        solve(s,0,s.size(),result,temp);
        return result;
    }
};