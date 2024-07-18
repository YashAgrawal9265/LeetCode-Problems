class Solution {
public:
    int characterReplacement(string str, int k) {
        int n = str.size();
        int l = 0, r = 0, ans=0, mxFreq = 0;
        unordered_map<char,int> mp;
        while(r < n){
            mp[str[r]]++;
            mxFreq = max(mxFreq,mp[str[r]]);
            while((r-l+1) - mxFreq > k){
                mp[str[l]]--;
                mxFreq = 0;
                for(auto it: mp) mxFreq = max(mxFreq,it.second);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};