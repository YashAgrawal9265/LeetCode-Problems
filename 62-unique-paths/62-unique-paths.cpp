class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = m + n - 2;
        int r = n-1;
        double result = 1;
        for(int i=1;i<=r;i++){
            result *= (x - r + i);
            result /= i;
        }
        return result;
    }
};