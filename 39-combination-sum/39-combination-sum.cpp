class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& arr, int idx, int target, vector<int>& temp){
        if(target == 0){
            result.push_back(temp);
            return;
        }
        if(idx >= arr.size()){
            return;
        }
        if(arr[idx] <= target){
            temp.push_back(arr[idx]);
            solve(arr,idx,target-arr[idx],temp);
            temp.pop_back();
        }
        solve(arr,idx+1,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> temp;
        solve(arr,0,target,temp);
        return result;
    }
};