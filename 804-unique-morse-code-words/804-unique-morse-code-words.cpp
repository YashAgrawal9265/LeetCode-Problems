class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mp = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        for(auto it: words){
            string str = "";
            for(auto i: it){
                str += mp[i-'a'];
            }
            st.insert(str);
        }
        return st.size();
    }
};