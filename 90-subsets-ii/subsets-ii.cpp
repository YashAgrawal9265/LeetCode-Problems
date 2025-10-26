class Solution {
public:
    void solve(vector<int>& arr, vector<int>& temp, vector<vector<int>>& result, int idx, int n){
        result.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i > idx and arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            solve(arr,temp,result,i+1, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,result,0,nums.size());
        return result;
    }
};