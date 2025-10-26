class Solution {
public:
    bool isPali(string& str, int i, int j){
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++,j--;
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
        int n= str.size();
        vector<string> temp;
        vector<vector<string>> result;
        solve(str,0,n,temp,result);
        return result;
    }
};