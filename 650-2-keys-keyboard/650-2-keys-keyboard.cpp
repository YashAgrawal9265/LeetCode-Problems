class Solution {
public:
    int solve(int screenCount, int n, int copiedCharCount, bool canCopy){
        if(screenCount > n) return 1e9;
        if(screenCount == n) return 0;
        
        int copy = 1e9;
        if(canCopy) 
            copy = 1 + solve(screenCount,n,screenCount,false);
        
        int paste = 1 + solve(screenCount+copiedCharCount, n, copiedCharCount,true);
        return min(copy,paste);
    }
    int minSteps(int n) {
        if(n == 1) return 0;
        return solve(0,n,1,false);
    }
};