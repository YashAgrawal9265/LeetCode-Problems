class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                string word = q.front().first;
                int length = q.front().second;
                q.pop();
                if(word == endWord) return length;
                for(int i=0;i<word.size();i++){
                    for(char c='a';c<='z';c++){
                        char orgChar = word[i];
                        word[i] = c;
                        if(st.find(word) != st.end()){
                            q.push({word,length+1});
                            st.erase(word);
                        }
                        word[i] = orgChar;
                    }
                }
            }
        }
        return 0;
        
    }
};