class Solution {
public:
    double solve(double base, long power){
        if(power == 0) return 1;
        if(power&1){
            return base*solve(base,power-1);
        }
        return solve(base*base,power/2);
    }
    double myPow(double x, int n) {
        if(n < 0){
            return 1 / solve(x,abs(n));
        }
        return solve(x,n);
    }
};