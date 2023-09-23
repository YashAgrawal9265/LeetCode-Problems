class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i=0;i<str.size();i++){
            if(str[i] == '(' or str[i] == '{' or str[i] == '['){
                st.push(str[i]);
            }
            else{
                if(st.empty()) return false;
                else if(str[i] == ')' and st.top() == '('){
                    st.pop();
                }
                else if(str[i] == '}' and st.top() == '{'){
                    st.pop();
                }
                else if(str[i] == ']' and st.top() == '['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size() > 0) return false;
        return true;
    }
};