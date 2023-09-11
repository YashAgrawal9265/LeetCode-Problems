class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        int st = arr[0][0];
        int en = arr[0][1];
        for(int i=1;i<arr.size();i++){
            if(arr[i][0] <= en){
                en = max(en,arr[i][1]);
            }
            else{
                result.push_back({st,en});
                st = arr[i][0];
                en = arr[i][1];
            }
        }
        result.push_back({st,en});
        return result;
    }
};