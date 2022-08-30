class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int idx = 0;
        stack<int> st;
        for(auto it: popped){
            while(st.empty() or st.top() != it){
                if(idx == n) return false;
                st.push(pushed[idx++]);
            }
            st.pop();
        }
        return true;
    }
};