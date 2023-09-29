class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        vector<int> mp(256,-1);
        int left = 0, right = 0, mxLen = 0;
        while(right < str.size()){
            if(mp[str[right]] != -1) left = max(left,mp[str[right]]+1);
            mp[str[right]] = right;
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};