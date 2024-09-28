class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto it: wordList){
            mp[it]++;
        }
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        while(!q.empty()){
            int steps = q.front().first;
            string word = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.size();i++){
                char curChar = word[i];
                for(char c = 'a'; c<= 'z'; c++){
                    word[i] = c;
                    if(mp.find(word) != mp.end()){
                        q.push({steps + 1, word});
                        mp[word]--;
                        if(mp[word] == 0) mp.erase(word);
                    }
                    word[i] = curChar;
                }
            }
        }
        return 0;
    }
};