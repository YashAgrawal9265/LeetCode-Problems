class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        for(auto it: words){
            string str = it;
            for(int i=1;i<str.size();i++){
                string temp = str.substr(i);
                if(st.find(temp) != st.end()){
                    st.erase(temp);
                }
            }
        }
        int result = 0;
        for(auto it = st.begin();it != st.end();it++){
            result += it->size() + 1;
        }
        return result;
    }
};