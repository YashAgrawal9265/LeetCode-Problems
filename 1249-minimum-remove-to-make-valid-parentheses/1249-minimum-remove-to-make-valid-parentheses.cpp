class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int n = str.size();
        stack<char> st;
        int open = 0;
        for(int i=0;i<n;i++){
            if(str[i] == ')' and open <= 0) continue;
            if(str[i] == '(') open++;
            else if(str[i] == ')') open--;
            st.push(str[i]);
        }
        int close = 0;
        string result = "";
        while(!st.empty()){
            if(st.top() == ')') close++;
            if(st.top() == '(' and close <= 0){
                st.pop();
                continue;
            }
            if(st.top() == '(') close--;
            result += st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};