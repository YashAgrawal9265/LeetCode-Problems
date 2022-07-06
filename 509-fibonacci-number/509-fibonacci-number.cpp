class Solution {
public:
    int fib(int n) {
        int prev_prev = 0, prev = 1;
        if(n == 0 || n == 1) return n; 
        for(int i=2;i<=n;i++){
            int cur = prev + prev_prev;
            prev_prev = prev;
            prev = cur;
        }
        return prev;
    }
};