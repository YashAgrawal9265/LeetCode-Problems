class Solution {
public:
    int mod = 1e9 + 7;
    int dp[18][10005];
    int memo[10005][18];
    int ncr(int n, int r){
        if(r > n) return 0;
        if(r == 0 or r == n) return 1;
        if(memo[n][r] != -1) return memo[n][r];
        return memo[n][r] = (ncr(n-1,r-1) + ncr(n-1,r)) % mod;
    }
    int solve(int idx,int val, int mxVal, int n){
        // if(idx == n) return 1;
        if(dp[idx][val] != -1) return dp[idx][val];
        int j = 2;
        if(val*j > mxVal){
            return dp[idx][val] = ncr(n-1,idx-1);
        }
        else{
            long long count = 0;
            while(val*j <= mxVal){
                count = (count + solve(idx+1,val*j,mxVal,n)) % mod;
                j++;
            }
            count = (count + ncr(n-1,idx-1)) % mod;
            return dp[idx][val] = count;
        }
    }
    int idealArrays(int n, int mxVal) {
        memset(dp,-1,sizeof(dp));
        memset(memo,-1,sizeof(memo));
        long long count = 0;
        for(int i=1;i<=mxVal;i++){
            count = (count + solve(1,i,mxVal,n)) % mod;
        }
        return count;
    }
};