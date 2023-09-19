class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
         int row = arr.size(), col = arr[0].size();
        int i = 0, j = col-1;
        while(i < row and j >= 0){
            if(arr[i][j] > target){
                j--;
            }
            else if(arr[i][j] < target){
                i++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};