class Solution {
public:
    int longestSubsequence(string str, int k) {
        long long num = 0;
        int len = 0;
        int n = str.size();
        int i;
        for(i=n-1;i>=0;i--){
            if(str[i] == '1'){
                if(num + pow(2,n-i-1) > k) break;
                num += pow(2,n-i-1);
            }
            len++;
        }
        for(i;i>=0;i--){
            if(str[i] == '0') len++;
        }
        return len;
    }
};