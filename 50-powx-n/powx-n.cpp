class Solution {
public:
    double solve(double base, long power){
        if(power == 1) return base;
        if(power%2 == 0){
            return solve(base*base,power/2);
        }
        return base*solve(base,power-1);
    }
    double myPow(double base, int power) {
        if(power == 0) return 1;
        if(power < 0){
            return 1.0/solve(base,abs(1L*power));
        }
        return solve(base,power);
    }
};