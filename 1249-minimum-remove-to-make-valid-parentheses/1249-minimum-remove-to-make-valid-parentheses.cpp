class Solution {
public:
    string minRemoveToMakeValid(string str) {
        int n = str.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(str[i] == '(') st.push(i);
            else if(str[i] == ')'){
                if(!st.empty() and str[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            str.erase(st.top(),1);
            st.pop();
        }
        
        return str;
    }
};