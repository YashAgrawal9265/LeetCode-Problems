class Solution {
public:
    int mod = 1e9 + 7;
    long long pow(long long base, long long power){
        long long result = 1;
        while(power){
            if(power&1){
                result = (result*base) % mod;
                power -= 1;
            }
            else{
                base = (base*base) % mod;
                power /= 2;
            }
        }
        return result % mod;
    }
    int countGoodNumbers(long long n) {
        if(n&1){
            return (pow(5,(n/2)+1)*pow(4,(n/2))) % mod;
        }
        return (pow(5,(n/2))*pow(4,(n/2))) % mod;
    }
};