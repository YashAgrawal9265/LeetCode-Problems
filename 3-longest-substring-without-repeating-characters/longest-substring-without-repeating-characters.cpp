class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int l = 0, r = 0;
        unordered_map<char,int> mp;
        int result = 0;
        while(r < n){
            if(mp.find(str[r]) != mp.end()){
                if(mp[str[r]] >= l)
                    l = mp[str[r]] + 1;
            }
            result = max(result, r-l+1);
            mp[str[r]] = r;
            r++;
        }
        return result;
    }

};