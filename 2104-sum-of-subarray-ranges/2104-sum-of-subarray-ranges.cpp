class Solution {
private:
    long long sumSubarrayMin(vector<int>& nums){
        int n = nums.size();
        long long result;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n || nums[i] < nums[st.top()])){
                int idx = st.top();
                int val = nums[idx];
                st.pop();
                int right = i - idx;
                int left;
                if(st.empty()){
                    left = idx + 1;
                }
                else{
                    left = idx - st.top();
                }
                result += (1LL*right*left*val);
            }
            st.push(i);
        }
        return result;
    }
private:
    long long sumSubarrayMax(vector<int>& nums){
        int n = nums.size();
        long long result;
        stack<int> st;
        for(int i=0;i<=n;i++){
            while(!st.empty() and (i == n || nums[i] > nums[st.top()])){
                int idx = st.top();
                int val = nums[idx];
                st.pop();
                int right = i - idx;
                int left;
                if(st.empty()){
                    left = idx + 1;
                }
                else{
                    left = idx - st.top();
                }
                result += (1LL*right*left*val);
            }
            st.push(i);
        }
        return result;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);
    }
};