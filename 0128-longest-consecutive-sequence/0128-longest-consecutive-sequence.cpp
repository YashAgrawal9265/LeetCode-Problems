class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(),nums.end());
        int mxLen = 0;
        for(auto it: nums){
            if(st.find(it+1) == st.end()){
                int temp = it-1;
                int len = 1;
                while(st.find(temp) != st.end()){
                    len++;
                    temp--;
                }
                mxLen = max(mxLen,len);
            }
        }
        return mxLen;
    }
};