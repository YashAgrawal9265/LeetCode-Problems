class Solution {
public:
    string removeKdigits(string str, int k) {
        stack<char> st;
        for(auto it: str){
            while(k and !st.empty() and st.top() > it){
                st.pop();
                k--;
            }
            st.push(it);
            if(st.size() == 1 and st.top() == '0') st.pop();
        }
        while(!st.empty() and k > 0) st.pop(), k--;
        if(st.empty()) return "0";
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(),result.end());
        return result;
    }
};