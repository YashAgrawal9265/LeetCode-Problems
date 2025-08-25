class Solution {
public:
    string minWindow(string str, string t) {
        if(t.size() > str.size()) return "";
        unordered_map<char,int> mp;
        for(auto it: t) mp[it]++;
        int winSize = mp.size();
        int l = 0, r= 0, result = INT_MAX, stIdx;
        while(r < str.size()){
            if(mp.find(str[r]) != mp.end()){
                mp[str[r]]--;
                if(mp[str[r]] == 0) winSize--;
            }
            while(winSize == 0){
                if((r-l+1) < result){
                    stIdx = l;
                    result = r-l+1;
                }
                if(mp.find(str[l]) != mp.end()){
                    mp[str[l]]++;
                    if(mp[str[l]] > 0) winSize++;
                }
                l++;
            }
            r++;
        }
        if(result >= INT_MAX) return "";
        return str.substr(stIdx,result);
    }
};