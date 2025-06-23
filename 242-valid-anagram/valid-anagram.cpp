class Solution {
public:
    bool isAnagram(string str, string t) {
        unordered_map<char,int> mp;
        for(auto it: str) mp[it]++;
        for(auto it: t) mp[it]--;
        for(auto it: mp) if(it.second != 0) return false;
        return true;
    }
};