class Solution {
public:
    void solve(vector<int>& arr, int n, int k, int idx, vector<vector<int>>& result, vector<int>& temp){
        
        if(k == 0){
            result.push_back(temp);
            return;
        }
        
        for(int i=idx;i<n;i++){
            
            if(i == idx || (i > idx && arr[i] != arr[i-1])){
                if(arr[i] <= k){
                    temp.push_back(arr[i]);
                    solve(arr,n,k-arr[i],i+1,result,temp);
                    temp.pop_back();
                }
                
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(arr,arr.size(),k,0,result,temp);
        return result;
    }
};