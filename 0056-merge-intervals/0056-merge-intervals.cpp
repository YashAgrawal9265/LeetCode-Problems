class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        for(int i=0;i<arr.size();i++){
            if(!result.empty() and result.back()[1] >= arr[i][0]){
                result.back()[1] = max(result.back()[1],arr[i][1]);
            }
            else{
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};