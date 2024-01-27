class Solution {
private:
    bool isPali(string& str){
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        return true;
    }
    void solve(string str, vector<vector<string>>& result, vector<string>& temp, int idx, int n){
        if(idx == str.size()){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            string substr = str.substr(idx,i-idx+1);
            if(isPali(substr)){
                temp.push_back(substr);
                solve(str,result,temp,i+1,n);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string str) {
        vector<vector<string>> result;
        vector<string> temp;
        solve(str,result,temp,0,str.size());
        return result;
    }
};