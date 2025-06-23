class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        for(auto it: strs){
            vector<int> count(26,0);
            for(auto i: it){
                count[i - 'a']++;
            }
            mp[count].push_back(it);
        }
        vector<vector<string>> result;
        for(auto it: mp) result.push_back(it.second);
        return result;
    }
};