class Solution {
public:
    int solve(vector<vector<int>>& arr, int a, int b){
        int maxi = -1;
        for(int i=a;i<(a+3);i++){
            for(int j=b;j<(b+3);j++){
                maxi = max(maxi,arr[i][j]);
            }
        }
        return maxi;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> result(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<n-2;j++){
                result[i][j] = solve(arr,i,j);
            }
        }
        return result;
    }
};