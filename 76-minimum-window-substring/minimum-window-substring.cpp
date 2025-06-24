class Solution {
public:
    string minWindow(string str, string t) {
        if(t.size() > str.size()) return "";
        unordered_map<char,int> mp;
        for(auto it: t) mp[it]++;

        int l = 0, r= 0, minLen = 1e8, stIdx = -1, cnt = 0;
        while(r < str.size()){
            if(mp[str[r]] > 0) cnt++;
            mp[str[r]]--;
            while(cnt == t.size()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    stIdx = l;
                }
                mp[str[l]]++;
                if(mp[str[l]] > 0) cnt--;
                l++;
            }
            r++;

        }
        return stIdx == -1 ? "" :  str.substr(stIdx,minLen);
    }
};