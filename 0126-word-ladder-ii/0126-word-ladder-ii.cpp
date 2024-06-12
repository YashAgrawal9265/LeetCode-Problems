class Solution {
private:
    void dfs(vector<string>& sec, unordered_map<string,int>& mp, string& beginWord, string& word,vector<vector<string>>& result){
        if(word == beginWord){
            reverse(sec.begin(),sec.end());
            result.push_back(sec);
            reverse(sec.begin(),sec.end());
            return;
        }
        int level = mp[word];
        for(int i=0;i<word.size();i++){
            for(char c='a';c<='z';c++){
                char orgChar = word[i];
                word[i] = c;
                if(mp.find(word) != mp.end() and mp[word] + 1 == level){
                    sec.push_back(word);
                    dfs(sec,mp,beginWord,word,result);
                    sec.pop_back();
                }
                word[i] = orgChar;
            }
        }
        
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        unordered_map<string,int> mp;
        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int level = mp[word];
            q.pop();
            if(word == endWord) break;
            for(int i=0;i<word.size();i++){
                for(char c='a';c<='z';c++){
                    char orgChar = word[i];
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        q.push(word);
                        st.erase(word);
                        mp[word] = level+1;
                    }
                    word[i] = orgChar;
                }
            }
        }
        vector<vector<string>> result;
        if(mp.find(endWord) != mp.end()){
            vector<string> sec;
            sec.push_back(endWord);
            dfs(sec,mp,beginWord,endWord,result);
        }
        return result;
    }
};