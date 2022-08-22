class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n > 0 and (n & (n-1)) == 0 and (n-1) % 3 == 0) return true;
        return false;
    }
};