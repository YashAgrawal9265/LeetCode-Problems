class Solution {
public:
    long long appealSum(string str) {
        int n = str.size();
        unordered_map<char,int> mp;
        vector<int> dp(n,0);
        dp[0] = 1;
        long long result = dp[0];
        mp[str[0]] = 0;
        for(int i=1;i<n;i++){
            if(mp.find(str[i]) == mp.end()){
                mp[str[i]] = i;
                dp[i] = dp[i-1] + (i+1);
            }
            else{
                dp[i] = dp[i-1] + (i-mp[str[i]]);
                mp[str[i]] = i;
            }
            result += dp[i];
        }
        return result;
    }
};