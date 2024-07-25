class Solution {
public:
    string minWindow(string str, string pattern) {
        int n = str.size();
        int l = 0, r = 0, stIdx = -1, mnLen = n+1;
        unordered_map<char,int> mp;
        for(auto it: pattern) mp[it]++;
        int patSize = pattern.size();
        int ele = 0;
        while(r < n){
            if(mp[str[r]] > 0) ele++;
            mp[str[r]]--;
            while(patSize == ele){
                if(r-l+1 < mnLen){
                    mnLen = r-l+1;
                    stIdx = l;
                }
                mp[str[l]]++;
                if(mp[str[l]] > 0) ele--;
                l++;
            }
            r++;
        }
        return stIdx == -1 ? "" : str.substr(stIdx,mnLen);
            
    }
};