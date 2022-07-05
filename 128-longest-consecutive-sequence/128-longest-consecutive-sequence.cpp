class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(),arr.end());
        int result = 0;
        for(int i=0;i<n;i++){
            if(st.find(arr[i]-1) == st.end()){
                int count = 1;
                int x = arr[i] + 1;
                while(st.find(x) != st.end()){
                    x++;
                    count++;
                }
                result = max(result,count);
            }
        }
        return result;
    }
};