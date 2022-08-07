class Solution {
public:
    long long dp[20005][26];
    int mod = 1e9 + 7;
    long long solve(int idx, int n, char prev){
        if(idx == n){
            return 1;
        }
        if(dp[idx][prev-'a'] != -1) return dp[idx][prev-'a'];
        if(prev == 'a'){
            return dp[idx][prev-'a'] = (solve(idx+1,n,'e')) % mod;
        }
        else if(prev == 'e'){
            return dp[idx][prev-'a'] = (solve(idx+1,n,'a') + solve(idx+1,n,'i')) % mod;
        }
        else if(prev == 'i'){
            return dp[idx][prev-'a'] = (solve(idx+1,n,'a') + solve(idx+1,n,'e') +                           solve(idx+1,n,'o') + solve(idx+1,n,'u')) % mod;
        }
        else if(prev == 'o'){
            return dp[idx][prev-'a'] = (solve(idx+1,n,'i') + solve(idx+1,n,'u')) % mod;
        }
        else if(prev == 'u'){
            return dp[idx][prev-'a'] = (solve(idx+1,n,'a')) % mod;
        }
        else{
            return dp[idx][prev-'a'] = (solve(idx+1,n,'a') + solve(idx+1,n,'e') +                            solve(idx+1,n,'i') + solve(idx+1,n,'o') + solve(idx+1,n,'u')) % mod;
        }
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,n,'b');
    }
};