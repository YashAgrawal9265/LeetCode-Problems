class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> mp;
        for(auto &it: words1){
            mp[it]++;
        }
        for(auto &it: words2){
            if(mp[it] < 2){
                mp[it]--;
            }
        }
        int result = 0;
        for(auto &it: mp){
            if(it.second == 0) result++;
        }
        return result;
    }
};