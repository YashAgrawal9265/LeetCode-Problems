class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        arr.push_back(newInterval);
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> result;
        for(int i=0;i<n;){
            vector<int> temp = arr[i];
            int j = i + 1;
            while(j < n){
                if(arr[j][0] <= temp[1]){
                    temp[1] = max(temp[1],arr[j][1]);
                }
                else{
                    break;
                }
                j++;
            }
            result.push_back(temp);
            i = j;
        }
        return result;
    }
};