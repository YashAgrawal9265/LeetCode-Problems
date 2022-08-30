class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        long long sum = 0;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n or arr[i] <= arr[st.top()])){
                int right = i;
                int ele = arr[st.top()];
                int idx = st.top();
                st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                int l = idx - left, r = right - idx;
                sum = (sum + 1LL*l*r*ele) % mod;
            }
            st.push(i);
        }
        return sum;
    }
};