class Solution {
private:
    bool static cmp(vector<int>& a, vector<int>& b){
        if(a[0] > b[0]) return true;
        else if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return false;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        stack<vector<int>> st;
        stack<vector<int>> temp_st;
       
        for(auto &it: arr){
            if(it[1] >= st.size()){
                st.push(it);
            }
            else{
                while(!st.empty() and it[1] < st.size()){
                    temp_st.push(st.top());
                    st.pop();
                }
                st.push(it);
                while(!temp_st.empty()){
                    st.push(temp_st.top());
                    temp_st.pop();
                }
            }
        }
        vector<vector<int>> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};