class Solution {
private:
    int val(char c){
        return c - 'a';
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(auto &word: words){
            vector<int> pattToWord(26,-1);
            vector<int> wordToPat(26,-1);
            bool flag = true;
            for(int i=0;i<pattern.size();i++){
                if(pattToWord[val(pattern[i])] == -1 and wordToPat[val(word[i])] == -1 ){
                    pattToWord[val(pattern[i])] = val(word[i]);
                    wordToPat[val(word[i])] = val(pattern[i]);
                }
                else if(pattToWord[val(pattern[i])] == val(word[i]) and  wordToPat[val(word[i])] == val(pattern[i])){
                    continue;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                result.push_back(word);
            }
        }
        return result;
    }
};