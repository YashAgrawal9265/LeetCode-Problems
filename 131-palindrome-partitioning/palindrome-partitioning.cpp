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
    void solve(string str, int idx, int n, vector<string>& temp, vector<vector<string>>& result, vector<vector<int>>& dp){
        if(idx >= n){
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<n;i++){
            if((str[idx] == str[i]) and (i-idx <= 1 or dp[idx+1][i-1] == 1)){
                dp[idx][i] = 1;
                temp.push_back(str.substr(idx,i-idx+1));
                solve(str,i+1,n,temp,result,dp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string str) {
        vector<vector<string>> result;
        vector<string> temp;
        int n=str.size() + 1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        solve(str,0,str.size(),temp,result,dp);
        
        return result;
    }
};