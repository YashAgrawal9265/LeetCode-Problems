class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int mp[256] = {0};
        int n = str.size();
        int right = 0, left = 0;
        int result = 0;
        while(right < n){
            mp[str[right]]++;
            while(mp[str[right]] > 1){
                mp[str[left]]--;
                left++;
            }
            result = max(result,right-left+1);
            right++;
        }
        return result;
    }
};