class Solution {
public:
    string minWindow(string str, string t) {
        if(t.size() > str.size()) return "";
        int n = str.size();
        int l = 0, r = 0, stIdx = -1, minLen = 1e9, cnt = 0;
        unordered_map<int,int> mp;
        for(auto it: t) mp[it]++;
        while(r < n){
            if(mp[str[r]] > 0) cnt++;
            mp[str[r]]--;
            while(cnt == t.size()){
                if((r-l+1) < minLen){
                    minLen = r-l+1;
                    stIdx = l;
                }
                mp[str[l]]++;
                if(mp[str[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(minLen == 1e9) return "";
        return str.substr(stIdx,minLen);
    }
};