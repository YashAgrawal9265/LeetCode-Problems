class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> prev_smaller(n), next_smaller(n);
        stack<int> pre_st, next_st;
        for(int i=0;i<n;i++){
            // calculating previous smaller
            while(!pre_st.empty() and arr[pre_st.top()] > arr[i]){
                pre_st.pop();
            }
            if(pre_st.empty()) prev_smaller[i] = -1;
            else prev_smaller[i] = pre_st.top();
            pre_st.push(i);
            
            // calculating next smaller
            while(!next_st.empty() and arr[next_st.top()] >= arr[n-i-1]){
               
                next_st.pop();
            }
            if(next_st.empty()) next_smaller[n-i-1] = n;
            else next_smaller[n-i-1] = next_st.top();
            next_st.push(n-i-1);
        }
        
        long long sum = 0;
        for(int i=0;i<n;i++){
            int left = i - prev_smaller[i];
            int right = next_smaller[i] - i;
            sum = (sum + 1LL*arr[i]*left*right) % mod;
        }
        return sum;
    }
};