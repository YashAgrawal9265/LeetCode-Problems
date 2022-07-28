class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> mp(26,0);
        for(auto it: s) mp[it-'a']++;
        for(auto it: t){
            mp[it-'a']--;
            if(mp[it-'a'] < 0) return false;
        }
        return true;
    }
};