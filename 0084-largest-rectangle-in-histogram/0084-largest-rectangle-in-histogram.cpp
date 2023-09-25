class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n= arr.size();
        stack<int> st;
        int maxi = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n or arr[i] <= arr[st.top()])){
                int height = arr[st.top()];
                st.pop();
                int right = i;
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                maxi = max(maxi,(right-left-1)*height);
            }
            st.push(i);
        }
        return maxi;
    }
};