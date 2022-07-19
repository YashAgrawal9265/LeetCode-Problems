class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n or nums[st.top()] >= nums[i])){
                int right = i;
                int minEle = nums[st.top()];
                st.pop();
                int left;
                if(!st.empty()) left = st.top();
                else left = -1;
                int size = right - left - 1;
                if(minEle > threshold/size){
                    return size;
                }
            }
            if(i < n) st.push(i);
        }
        return -1;
    }
};