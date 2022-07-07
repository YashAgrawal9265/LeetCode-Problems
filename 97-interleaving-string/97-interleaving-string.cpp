class Solution {
private:
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(m + n  != s3.size()) return false;
        vector<int> prev(n+1,0), cur(n+1,0);
        prev[0] = 1;
        cur[0] = 1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 and j == 0) continue;
                int result = 0;
                if(i-1 >= 0 and j-1 >= 0 and s3[i+j-1] == s2[j-1] and s3[i+j-1] == s1[i-1]){
                    result = prev[j] or cur[j-1];
                }
                else if(j-1 >= 0 and s3[i+j-1] == s2[j-1]){
                    result = cur[j-1];
                }
                else if(i-1 >= 0 and s3[i+j-1] == s1[i-1]){
                    result = prev[j];
                }
                cur[j] = result;
            }
            prev = cur;
        }
        return prev[n];
    }
};