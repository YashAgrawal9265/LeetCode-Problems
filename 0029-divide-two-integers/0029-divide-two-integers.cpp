class Solution {
public:
    int divide(int dividend, int divisor) {
        // INT_MIN = -2^31;
        if(dividend == INT_MIN and divisor == -1){
            return INT_MAX; // 2^31 - 1;
        }
        
        int sign;
        
        
        // if both dividend and divisor having same sign then 
        // sign is positive else negative
        if((dividend < 0) ^ (divisor < 0)){
            sign = -1;
        }
        else{
            sign = 1;
        }
        
        
        
        // update dividend and divisor to positive
        long long divid = abs(dividend);
        long long divis = abs(divisor);
        
        long long result = 0;
        while(divid - divis >= 0){
            int count = 0; // 2^0 = 1
            while(divid - (divis << 1 << count) >= 0){
                count++;
            }
            result += 1 << count;
            divid -= divis << count;
        }
       
        return result*sign;
    }
};