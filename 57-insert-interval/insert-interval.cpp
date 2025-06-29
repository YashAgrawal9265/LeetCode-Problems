class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        int n = arr.size();
        vector<vector<int>> result;
        vector<int> temp = newInterval;
        int i = 0;
        while(i < n and arr[i][1] < temp[0]){
            result.push_back(arr[i]);
            i++;
        }

        while(i < n and temp[1] >= arr[i][0]){
            temp[0] = min(temp[0],arr[i][0]);
            temp[1] = max(temp[1],arr[i][1]);
            i++;
        }
        result.push_back(temp);

        while(i < n){
            result.push_back(arr[i]);
            i++;
        }   
        return result;

    }
};