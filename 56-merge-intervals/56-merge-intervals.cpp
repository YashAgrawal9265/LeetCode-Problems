class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        for(int i=0;i<arr.size();){
            vector<int> temp = arr[i];
            int j = i + 1;
            while(j < arr.size() and arr[j][0] <= temp[1]){
                temp[1] = max(temp[1],arr[j][1]);
                j++;
            }
            result.push_back(temp);
            i = j;
        }
        return result;
    }
};