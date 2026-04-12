class Solution {
public:
    void solve(vector<int>& arr, int idx, int k, vector<int>& temp, vector<vector<int>>& result){
        if(k == 0){
            result.push_back(temp);
            return;
        }
        if(idx < 0) return;
        temp.push_back(arr[idx]);
        solve(arr,idx-1,k-1,temp,result);
        temp.pop_back();
        solve(arr,idx-1,k,temp,result);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i=1;i<=n;i++) arr.push_back(i);
        vector<vector<int>> result;
        vector<int> temp;
        solve(arr,n-1,k,temp,result);
        return result;
    
    }
};