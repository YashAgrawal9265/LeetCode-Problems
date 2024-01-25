class Solution {
private:
    double solve(double base, long power){
        if(power == 0) return 1.0;
        if(power&1){
            return base*solve(base,power-1);
        }
        double x = solve(base,power/2);
        return x*x;
    }
public:
    double myPow(double x, int n) {
        long power = n;
        if(n < 0) power *= -1;
        double ans = solve(x,power);
        if(n < 0) return 1.0/ans;
        return ans;
    }
};