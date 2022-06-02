class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalPath = m+n-2;
        int r = n-1;
        double result = 1;
        for(int i=1;i<=r;i++){
            result *= (totalPath-r+i);
            result /= i;
        }
        return (int)result;
    }
};