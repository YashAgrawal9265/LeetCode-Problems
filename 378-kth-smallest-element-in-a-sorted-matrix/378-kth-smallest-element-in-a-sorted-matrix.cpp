class Solution {
public:
    int countSmaller(int mid, vector<vector<int>>& mat, int n){
        int i = 0 , j = n-1;
        int count =0;
        while(i < n and j >= 0){
            if(mat[i][j] <= mid){
                count += (j+1);
                i++;
            }
            else{
                j--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(countSmaller(mid,mat,n) < k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        if(countSmaller(low,mat,n) >= k) return low;
        return high;
    }
};