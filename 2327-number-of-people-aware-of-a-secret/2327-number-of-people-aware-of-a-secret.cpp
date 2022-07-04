class Solution {
private:
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        dp[1] = 1;
        for(int i=1;i<=n;i++){
            for(int j=i+delay; j<=min(n,i+forget-1); j++){
                dp[j] = (dp[j] + dp[i]) % mod;
            }
        }
        
        
        long long result = 0;
        for(int i=n;i>=max(0,n-forget+1);i--){
            result = (result + dp[i]) % mod;
        }
        return result;
    }
};