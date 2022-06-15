class Solution {
public:
    bool static cmp(string& a, string& b){
        return a.size() < b.size();
    }
    // a is smaller than b
    bool isValid(string& a, string& b){
        int m = a.size(), n = b.size();
        if(m + 1 != n) return false;
        int i=0,j=0;
        bool flag = true;
        while(i<m and j<n){
            if(a[i] == b[j]){
                i++,j++;
            }
            else if(a[i] != b[j] and flag == true){
                j++;
                flag = false;
            }
            else{
                return false;
            }
        }
        if(i == m) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        
        int n = words.size();
        int mxLen = -1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev = 0; prev < i; prev++){
                if(isValid(words[prev],words[i])){
                    dp[i] = max(dp[i],dp[prev]+1);
                }
            }
            mxLen = max(mxLen,dp[i]);
        }
        return mxLen;
    }
};