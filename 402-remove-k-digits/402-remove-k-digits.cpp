class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top() > str[i] and k > 0){
                st.pop();
                k--;
            }
            st.push(str[i]);
        }
        while(k--){
            st.pop();
        }
        string result = "";
        while(!st.empty()) result += st.top(), st.pop();
        reverse(result.begin(),result.end());
        int i;
        for(i=0;i<result.size() and result[i]=='0';i++);
        result = result.substr(i);
        return result == "" ? "0": result;
    }
};