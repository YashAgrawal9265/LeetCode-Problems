class Solution {
public:
    void solve(vector<int>& arr, int idx, int k, vector<vector<int>>& result, vector<int>& temp){
        if(idx < 0){
            if(k == 0)
                result.push_back(temp);
            return;
        }
        if(arr[idx] <= k){
            temp.push_back(arr[idx]);
            solve(arr,idx,k-arr[idx],result,temp);
            temp.pop_back();
        }
        solve(arr,idx-1,k,result,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(arr,arr.size()-1,k,result,temp);
        return result;
    }
};