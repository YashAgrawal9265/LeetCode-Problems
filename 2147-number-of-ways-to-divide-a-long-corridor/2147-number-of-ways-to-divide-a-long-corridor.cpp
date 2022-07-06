class Solution {
private:
    int mod = 1e9 + 7;
public:
    long long solve(string& str, int idx, int seats, vector<vector<int>>& dp){
        if(idx == str.size()){
            if(seats == 2) return 1;
            return 0;
        }
        if(dp[idx][seats] != -1) return dp[idx][seats];
        long long count = 0;
        if(seats == 2){
            if(str[idx] == 'P'){
                count += solve(str,idx+1,0,dp);
                count %= mod;
                count += solve(str,idx+1,seats,dp);
                count %= mod;
            }
            else{
                count += solve(str,idx+1,1,dp);
                count %= mod;
            }
        }
        else{
            if(str[idx] == 'S') count += solve(str,idx+1,seats + 1,dp);
            else count += solve(str,idx+1,seats,dp);
            count %= mod;
        }
        return dp[idx][seats] = count;
    }
    int numberOfWays(string str) {
        int n = str.size();
        vector<vector<int>> dp(n+1, vector<int>(3,-1));
        return solve(str,0,0,dp);
    }
};