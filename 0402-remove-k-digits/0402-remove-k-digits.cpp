class Solution {
public:
    string removeKdigits(string str, int k) {
        int n = str.size();
        if(n == k) return "0";
        if(k == 0) return str;
        stack<char> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top() - '0' > str[i] - '0' and k > 0){
                st.pop();
                k--;
            }
            if(str[i] == '0' and st.empty()) continue;
            st.push(str[i]);
        }
        while(k > 0 and !st.empty()){
            st.pop();
            k--;
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        if(result == "") return "0";
        reverse(result.begin(),result.end());
        return result;
    }
};