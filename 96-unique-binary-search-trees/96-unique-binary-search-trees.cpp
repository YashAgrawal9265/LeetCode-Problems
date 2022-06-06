class Solution {
public:
    long long ncr(int n, int r){
        long long result = 1;
        for(int i=1;i<=r;i++){
            result = 1LL*result*(n-r+i);
            result /= i;
        }
        return result;
    }
    int numTrees(int n) {
        long long x = ncr(2*n,n);
    
        return x/(n+1);
    }
};