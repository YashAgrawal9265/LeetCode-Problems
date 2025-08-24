class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size(), left = 0, right = 0, leftMx = 0, rightMx = 0, result = 0;
        int l = 0, r = n-1;
        while(l <= r){
            if(arr[l] <= arr[r]){
                leftMx = max(leftMx,arr[l]);
                result += (leftMx - arr[l]);
                l++;
            }
            else{
                rightMx = max(rightMx,arr[r]);
                result += (rightMx - arr[r]);
                r--;
            }
        }     
        return result; 
    }
};