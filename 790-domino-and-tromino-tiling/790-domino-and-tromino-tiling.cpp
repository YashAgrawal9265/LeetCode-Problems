class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        // formula:
        // f(n) = f(n-1) + f(n-2) + 2*g(n-1);
        // g(n) = f(n-2) + g(n-2);
        long long fn[n+1], gn[n+1];
        fn[0] = 1, gn[0] = 0;
        fn[1] = 1, gn[1] = 0;
        for(int i=2;i<=n;i++){
            fn[i] = ((fn[i-1] + fn[i-2])%mod + (2*gn[i-1])%mod) % mod;
            gn[i] = (fn[i-2] + gn[i-1]) % mod;
        }
        return fn[n];
        
    }
};