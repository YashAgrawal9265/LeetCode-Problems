class Solution {
public:
    int longestSubsequence(string str, int k) {
        long long num = 0;
        int len = 0;
        int zeroCount = 0;
        int n = str.size();
        for(int i=0;i<n;i++){
            if(str[i] == '0') zeroCount++;
        }
        for(int i=n-1;i>=0;i--){
            if(str[i] == '1'){
                if(num + pow(2,n-i-1) > k) break;
                num += pow(2,n-i-1);
            }
            if(str[i] == '0') zeroCount--;
            len++;
        }
        return len + zeroCount;
    }
};