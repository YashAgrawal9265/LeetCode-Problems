class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int l = 0, r = 0;
        unordered_map<char,int> mp;
        int result = 0;
        while(r < n){
            mp[str[r]]++;
            while(mp[str[r]] > 1){
                mp[str[l]]--;
                l++;
            }
            result = max(result, r-l+1);
            r++;
        }
        return result;
    }

};