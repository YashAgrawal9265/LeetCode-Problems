class Solution {
public:
    int removePalindromeSub(string str) {
        int n = str.size();
        if(n == 0) return 0;
        int i=0, j = n-1;
        while(i<j){
            if(str[i] != str[j]){
                break;
            }
            i++,j--;
        }
        if(i >= j) return 1;
        return 2;
    }
};