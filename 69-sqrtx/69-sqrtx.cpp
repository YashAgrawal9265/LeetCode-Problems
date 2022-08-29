class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(true){
            if(1LL*i*i > x){
                return i-1;
            }
            i++;
        }
        return i;
    }
};