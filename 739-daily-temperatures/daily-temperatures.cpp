class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> result(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()) result[i] = st.top() - i;
            st.push(i);
        }
        return result;
    }
};