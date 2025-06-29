class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> result;
        sort(arr.begin(),arr.end());
        vector<int> temp = arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] <= temp[1]){
                temp[1] = max(arr[i][1],temp[1]);
            }
            else{
                result.push_back(temp);
                temp = arr[i];
            }
        }
        result.push_back(temp);
        return result;
    }
};