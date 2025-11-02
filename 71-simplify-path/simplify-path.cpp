class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        int l = 0, r=1;
        string str = "";
        while(r <= n){
            // cout<<str<<endl;
            if(path[r] == '/' or r == n){
                if(str.size() > 0) st.push(str);
                str = "";
                if(!st.empty() and st.top() == ".."){
                    st.pop();
                    if(!st.empty()) st.pop();
                }
                if(!st.empty() and st.top() == ".") st.pop();
            }
            else{
                str += path[r];
            }
            r++;
        }
        if(str.size() > 0) st.push(str);
        if(st.empty()) return "/";
        string result = "";
        while(!st.empty()){
            // cout<<st.top()<<endl;
            string temp = st.top();
            result = st.top() + "/" + result;
            st.pop();
        }
        result = "/" + result;
        result.pop_back();
        return result;
    }
};