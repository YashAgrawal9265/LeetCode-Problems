class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;
        int leftMx = -1, rightMx = -1, result = 0;
        while(l <= r){
            if(arr[l] < arr[r]){
                leftMx = max(leftMx,arr[l]);
                result += leftMx-arr[l];
                l++;
            }
            else{
                rightMx = max(rightMx,arr[r]);
                result += rightMx-arr[r];
                r--;
            }
        }
        return result;
    }
};