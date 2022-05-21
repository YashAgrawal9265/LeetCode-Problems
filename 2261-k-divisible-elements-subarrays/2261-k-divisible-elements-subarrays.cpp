class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            int count = 0;
            string temp = "";
            for(int j=i;j<n;j++){
                if(nums[j] % p == 0) count++;
                if(count > k) break;
                temp += to_string(nums[j]) + '-';
                st.insert(temp);
            }
        }
        
        return st.size();
    }
};