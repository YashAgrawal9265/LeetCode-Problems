class Solution {
public:
    int numMatchingSubseq(string str, vector<string>& words) {
        int n = str.size();
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]].push_back(i);
        }
        int count = 0;
        for(auto &it: words){
            string word = it;
            int last = -1;
            int i;
            for(i=0;i<word.size();i++){
                auto it = upper_bound(mp[word[i]].begin(), mp[word[i]].end(), last);
                if(it == mp[word[i]].end()) break;
                last = *it;
            }
            if(i == word.size()) count++;
        }
        return count;
    }
};