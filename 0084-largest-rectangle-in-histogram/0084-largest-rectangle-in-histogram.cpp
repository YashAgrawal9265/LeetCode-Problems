class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
      
        int n = arr.size();
        vector<int> left_smaller(n), right_smaller(n);
        
        // finding left smaller element
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) left_smaller[i] = -1;
            else left_smaller[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        
        // finding right smaller element
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[st.top()] >= arr[i]) st.pop();
            if(st.empty()) right_smaller[i] = n;
            else right_smaller[i] = st.top();
            st.push(i);
        }
        
       
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            int left = left_smaller[i];
            int right = right_smaller[i];
            
            maxi = max(maxi, (right-left-1)*arr[i]);
            
        }
        return maxi;
    }
};