class Solution {
public:
    unordered_set<string> st;
    vector<string> temp;
    vector<string> result;
    void solve(string& str, int idx, int n){
        if(idx >= n){
            string s = "";
            for(auto it: temp){
                s += it + " ";
            }
            s.pop_back();
            result.push_back(s);
            return;
        }
        for(int i=idx;i<n;i++){
            string s = str.substr(idx,i-idx+1);
            if(st.find(s) != st.end()){
                temp.push_back(s);
                solve(str,i+1,n);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string str, vector<string>& wordDict) {
        
        for(auto it: wordDict) st.insert(it);
        solve(str,0,str.size());
        return result;
    }
};