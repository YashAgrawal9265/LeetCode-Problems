class Solution {
public:
    bool static cmp(string& a, string& b){
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        unordered_set<string> st;
        int result = 0;
        for(int i=0;i<words.size();i++){
            string str = words[i];
            if(st.find(str) != st.end()) continue;
            // cout<<str<<endl;
            int start = str.size()-1;
            while(start >= 0){
                st.insert(str.substr(start));
                start--;
            }
            result += str.size() + 1;
        }
        return result;
    }
};