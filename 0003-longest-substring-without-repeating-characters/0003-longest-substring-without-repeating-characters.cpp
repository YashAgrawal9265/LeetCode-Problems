class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int left = 0, right = 0;
        int map[257] = {0};
        int mxLen = 0;
        while(right < str.size()){
            map[str[right]]++;
            while(left < right and map[str[right]] > 1){
                map[str[left]]--;
                left++;
            }
            mxLen = max(mxLen,right-left+1);
            right++;
        }
        return mxLen;
    }
};