class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        for(auto it: wordList) st.insert(it);
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            // int size = q.size();
            // while(size--){
                string word = q.front().first;
                int level = q.front().second;
                if(word == endWord) return level;
                q.pop();
                for(int i=0;i<word.size();i++){
                    string temp_word = word;
                    for(int k=0;k<26;k++){
                        temp_word[i] = k + 'a';
                        if(st.find(temp_word) != st.end()){
                            q.push({temp_word,level+1});
                            st.erase(temp_word);
                        }
                    }    
                }
                
            
        }
        return 0;
    }
};