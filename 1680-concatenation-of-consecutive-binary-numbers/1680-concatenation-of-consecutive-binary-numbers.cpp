class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long result = 0;
        for(int i=1;i<=n;i++){
            result = ((result << (1+(int)log2(i))%mod) + i)%mod;
        }
        return result;
    }
};