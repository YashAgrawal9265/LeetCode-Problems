class Solution {
public:
    int characterReplacement(string str, int k) {
        int n = str.size();
        int left = 0, right = 0, mxLen = 0, mxFreq = 0;
        unordered_map<char,int> mp;
        while(right < n){
            mp[str[right]]++;
            mxFreq = max(mxFreq,mp[str[right]]);
            while(right - left + 1 - mxFreq > k){
                mp[str[left]]--;
                left++;
                mxFreq = max(mxFreq,mp[str[left]]);
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};