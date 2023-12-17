class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxi = 0;
        for(auto it: nums){
            if(st.find(it-1) == st.end()){
                int num = it+1;
                int count = 1;
                while(st.find(num) != st.end()){
                    num++;
                    count++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};