class Solution {
public:
    int mySqrt(int x) {
        
        
        int l = 0, h = x;
        while(h-l > 1){
            int mid = (l + h) >> 1;
            if(1LL*mid*mid <= x) l = mid;
            else h = mid - 1;
        }
        if(h*h <= x) return h;
        return l;
    }
};