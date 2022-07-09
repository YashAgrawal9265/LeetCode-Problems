class Solution {
public:
    int solve(vector<int>& arr, vector<int>& vis, int idx, int n){
        vis[idx] = 1;
        if(arr[idx] == 0) return true;
        bool result = false;
        for(int i=0;i<2;i++){
            int new_idx;
            if(i == 0) new_idx = idx + arr[idx];
            else new_idx = idx - arr[idx];
            if(new_idx >= 0 and new_idx < n and !vis[new_idx]){
                result = result or solve(arr,vis,new_idx,n);
            }
        }
        return result;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return solve(arr,vis,start,n);
    }
};