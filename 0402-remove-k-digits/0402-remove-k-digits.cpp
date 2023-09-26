class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top() > str[i]-'0' and k > 0){
                st.pop();
                k--;
            }
            if(str[i] == '0' and st.empty()) continue;
            st.push(str[i]-'0');
        }
        while(!st.empty() and k--) st.pop();
        string result = "";
        while(!st.empty()){
            result += (st.top() + '0');
            st.pop();
        }
        if(result == "") return "0";
        reverse(result.begin(),result.end());
        return result;
    }
};