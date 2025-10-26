class Solution {

public:
    bool isPali(string& str, int i, int j){
        while(i <= j){
            if(str[i] != str[j]) return false;
            i++,j--;
        }
        return true;
    }
    void solve(string str, int idx, int n, vector<string>& temp, vector<vector<string>>& result, vector<vector<int>>& dp){
        if(idx >= n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if(str[i] == str[idx] and (i-idx <=2 || dp[idx+1][i-1])){
                dp[idx][i] = 1;
                temp.push_back(str.substr(idx,i-idx+1));
                solve(str,i+1,n,temp,result,dp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        int n= str.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        vector<string> temp;
        vector<vector<string>> result;
        solve(str,0,n,temp,result,dp);
        return result;
    }
};