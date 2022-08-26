class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int left = 0, right = 0, mxLen = 0;
        unordered_map<char,int> mp;
        while(right < n){
            mp[str[right]]++;
            while(mp[str[right]] > 1){
                mp[str[left]]--;
                left++;
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};