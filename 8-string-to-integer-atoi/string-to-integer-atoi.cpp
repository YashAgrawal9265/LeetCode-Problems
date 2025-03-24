class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int result = 0;
        int sign = 1, i = 0;
        while(i < n and str[i] == ' ') i++;

        if(i < n){
            if(str[i] == '-'){
                sign = -1;
                i++;
            }
            else if(str[i] == '+'){
                sign = +1;
                i++;
            }
        }

        while(i < n){
            if(str[i] >= '0' and str[i] <= '9'){
                int num = str[i] - '0';
                if(result > (INT_MAX - num) / 10){
                    if(sign == -1) return INT_MIN;
                    else return INT_MAX;
                }
                result = (result*10) + num;
                i++;
            }
            else break;
        }
        return sign*result;
    }
};