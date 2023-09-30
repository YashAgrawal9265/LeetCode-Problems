class Solution {
public:
    int characterReplacement(string str, int k) {
        int left = 0, right = 0;
        unordered_map<char,int> mp;
        int mxFreq = 0, mxLen = 0;
        while(right < str.size()){
            mp[str[right]]++;
            mxFreq = max(mxFreq,mp[str[right]]);
            while((right - left + 1 ) - mxFreq > k){
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