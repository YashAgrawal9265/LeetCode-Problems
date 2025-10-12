class Solution {
public:
    string minWindow(string str, string t) {
        int n = str.size();
        int left = 0, right = 0, mnLen = 1e8, stIdx = 0;
        unordered_map<char,int> mp;
        for(auto it: t) mp[it]++;
        int winSize = mp.size();
        while(right < n){
            if(mp.find(str[right]) != mp.end()){
                mp[str[right]]--;
                if(mp[str[right]] == 0) winSize--;
            }
            while(winSize == 0){
                if((right-left+1) < mnLen){
                    mnLen = right-left+1;
                    stIdx = left;
                }
                if(mp.find(str[left]) != mp.end()){
                    mp[str[left]]++;
                    if(mp[str[left]] > 0) winSize++;
                }
                left++;
            }
            right++;
        }
        return mnLen >= 1e8 ? "" : str.substr(stIdx,mnLen);
    }
};