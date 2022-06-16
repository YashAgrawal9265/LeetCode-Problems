class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        int mxLen = INT_MIN, endIdx;
        for(int gap = 0; gap < n; gap++){
            for(int i=0, j=gap; j<n; i++,j++){
                if(gap == 0){
                    dp[i][j] = 1;
                }
                else if(gap == 1){
                    dp[i][j] = (str[i] == str[j]);
                }
                else{
                    if(str[i] == str[j] and dp[i+1][j-1]){
                        dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
                if(dp[i][j] and gap + 1 > mxLen){
                    mxLen = gap + 1;
                    endIdx = j;
                }
            }
        }
        return str.substr(endIdx-mxLen+1, mxLen);
    }
};