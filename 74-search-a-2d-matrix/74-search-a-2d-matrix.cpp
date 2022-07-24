class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m*n - 1;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(mat[mid/n][mid%n] <= target){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        if(mat[low/n][low%n] == target) return true;
        if(mat[high/n][high%n] == target) return true;
        return false;
    }
};