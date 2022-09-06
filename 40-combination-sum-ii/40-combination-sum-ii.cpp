class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& arr, int idx, int target, vector<int>& temp){
        if(target == 0){
            result.push_back(temp);
            return;
        } 
        for(int i=idx;i<arr.size();i++){
            if(i-1 >= idx and arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            temp.push_back(arr[i]);
            solve(arr,i+1,target-arr[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> temp;
        sort(arr.begin(),arr.end());
        solve(arr,0,target,temp);
        return result;
    }
};