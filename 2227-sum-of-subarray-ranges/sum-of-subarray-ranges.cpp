class Solution {
public:
    long long solve(vector<int>& arr) {
        // int mod = 1e9 + 7;
        int n = arr.size();
        stack<long long> st;
        long long result = 0;
        for(int i=0;i<=n;i++){
            while((i == n and !st.empty()) or (!st.empty() and arr[st.top()] > arr[i])){
                int right = i;
                int eleIdx = st.top();
                st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                result = result +  (1LL*arr[eleIdx]*(eleIdx-left)*(right-eleIdx));
            }
            st.push(i);
        }
        return result;
    }
    long long solve2(vector<int>& arr) {
        // int mod = 1e9 + 7;
        int n = arr.size();
        stack<long long> st;
        long long result = 0;
        for(int i=0;i<=n;i++){
            while((i == n and !st.empty()) or (!st.empty() and arr[st.top()] < arr[i])){
                int right = i;
                int eleIdx = st.top();
                st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                result = result +  (1LL*arr[eleIdx]*(eleIdx-left)*(right-eleIdx));
            }
            st.push(i);
        }
        return result;
    }
    long long subArrayRanges(vector<int>& nums) {
        return solve2(nums) - solve(nums);
    }
};