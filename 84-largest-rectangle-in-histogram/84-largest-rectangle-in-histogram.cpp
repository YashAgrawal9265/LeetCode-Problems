class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        int result = -1;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n or arr[st.top()] > arr[i])){
                int right = i;
                int ele = arr[st.top()];
                st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                result = max(result,(right-left-1)*ele);
            }
            st.push(i);
        }
        return result;        
                  
    }
};