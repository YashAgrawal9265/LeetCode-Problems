class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        vector<int> temp = arr[0];
        int i = 1;
        while(i < n){
            if(arr[i][0] > temp[1]){
                result.push_back(temp);
                temp = arr[i];
            }
            else{
                temp[1] = max(temp[1],arr[i][1]);
            }
            i++;
        }
        result.push_back(temp);
        return result;
    }
};