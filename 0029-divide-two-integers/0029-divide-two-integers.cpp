class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        int sign = -1;
        if((divisor >= 0 and dividend >= 0) or (divisor < 0 and dividend < 0))
            sign = 1;
        long n = abs(dividend);
        long d=abs(divisor);
        long ans = 0;
        while(n >= d){
            int cnt = 0;
            while(n > (d<<(cnt+1))){
                cnt++;
            }
            
            ans += 1<<cnt;
            n -= (d<<cnt);
        }
        
        long a = 1, b = 31;
   
        if(ans == (a<<b) and sign == 1){
           return INT_MAX;
        }
        if(ans == (a<<b) and sign == -1) return INT_MIN;
        if(sign == -1) return -ans;
        return ans;
            
        
    }
};