class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& arr) {
        int n= arr.size();
        vector<int> st;
        vector<int> en;
        for(auto it: arr){
            st.push_back(it[0]);
            en.push_back(it[1]);
        }
        sort(st.begin(),st.end());
        sort(en.begin(),en.end());

        int i = 1, j = 0;
        int count = 1, maxi = 1;
        while(i < n and j < n){
            if(st[i] < en[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};