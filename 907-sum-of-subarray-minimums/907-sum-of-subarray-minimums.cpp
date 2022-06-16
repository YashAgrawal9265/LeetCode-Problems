class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int mod = 1e9 + 7;
        int n = nums.size();
        
        // finding minimum element
        // using next smaller and previous smaller
        stack<int> st;
        long long result = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n || nums[st.top()] > nums[i])){
                int idx = st.top();
                int right = i - idx;
                int val = nums[idx];
                st.pop();
                int left;
                if(st.empty()){
                    left = idx - (-1);
                }
                else{
                    left = idx-st.top();
                }
                result = (result + 1LL*right*left*val) % mod;
            }
            st.push(i);
        }
        return result;
    }
};