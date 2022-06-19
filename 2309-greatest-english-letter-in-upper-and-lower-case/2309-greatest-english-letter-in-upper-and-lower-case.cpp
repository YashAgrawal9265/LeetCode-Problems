class Solution {

public:
    string greatestLetter(string str) {
        int mp[257] = {0};
        for(auto it: str){
            mp[it]++;
        }
        for(char c = 'Z'; c>='A'; c--){
            if(mp[c] and mp[c+32]){
                return string(1,c);
            }
        }
        return "";
        
    }
};