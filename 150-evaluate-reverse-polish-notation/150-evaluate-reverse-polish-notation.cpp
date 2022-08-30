class Solution {
private:
    int solve(int x, int y, string c){
        if(c == "+") return x + y;
        if(c == "-") return x - y;
        if(c == "*") return x*y;
        if(c == "/") return x/y;
        return 0;
    }
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;
        for(auto it: arr){
            if(it != "+" and it != "-" and it != "*" and it != "/"){
                st.push(stoi(it));
            }
            else{
                int val2 = st.top();
                st.pop();
                int val1 = st.top();
                st.pop();
                st.push(solve(val1,val2,it));
            }
        }
        return st.top();
    }
};