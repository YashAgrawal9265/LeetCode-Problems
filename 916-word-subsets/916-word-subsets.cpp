class Solution {
public:
    void counter(vector<string>& arr, vector<int>& mp){
        for(auto it: arr){
            vector<int> temp(26,0);
            for(auto i: it){
                temp[i-'a']++;
                mp[i-'a'] = max(mp[i-'a'],temp[i-'a']);
            }
        }
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> mp(26,0);
        counter(words2,mp);
        vector<string> result;
        for(auto &it: words1){
            vector<int> temp(26,0);
            for(auto &i: it){
                temp[i-'a']++;
            }
            bool flag = true;
            for(int i=0;i<26;i++){
                if(temp[i] < mp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag) result.push_back(it);
        }
        return result;
    }
};