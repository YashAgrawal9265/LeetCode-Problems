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
        string result = "";
        for(int i=n-1;i>=0;i--){
            if(!st.empty() and i == st.top()){
                st.pop();
                continue;
            }
            result += str[i];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};