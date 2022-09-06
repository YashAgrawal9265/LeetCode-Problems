class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& arr, int idx, int n){
        if(idx == n){
            result.push_back(arr);
            return;
        }
        unordered_set<int> st;
        for(int i=idx;i<n;i++){
            if(st.find(arr[i]) != st.end()) continue;
            st.insert(arr[i]);
            swap(arr[idx],arr[i]);
            solve(arr,idx+1,n);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n = arr.size();
        solve(arr,0,n);
        return result;
    }
};