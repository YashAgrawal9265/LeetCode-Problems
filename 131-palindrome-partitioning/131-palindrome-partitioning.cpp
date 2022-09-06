class Solution {
public:
    vector<vector<string>> result;
    bool isPali(string& str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        return true;
    }
    void solve(string& str, int idx, int n, vector<string>& temp){
        if(idx >= n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(isPali(str,idx,i)){
                string s = str.substr(idx,i-idx+1);
                temp.push_back(s);
                solve(str,i+1,n,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
       vector<string> temp;
        solve(str,0,str.size(),temp);
        return result;
    }
};