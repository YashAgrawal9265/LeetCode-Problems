class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        vector<int> mp(257,0);
        int left = 0, right = 0, result = 0;
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