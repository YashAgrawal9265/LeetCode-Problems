class Solution {
    
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    int countVowelSubstrings(string str) {
        int n = str.size();
        int count = 0;
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=i;j<n;j++){
                if(isVowel(str[j])){
                    st.insert(str[j]);
                }
                else{
                    break;
                }
                if(st.size() == 5) count++;
            }
        }
        return count;
    }
};