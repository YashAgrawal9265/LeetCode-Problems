class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1, left_mx = arr[0], right_mx = arr[n-1], result = 0;
        while(l <= r){
            if(arr[l] < arr[r]){
                left_mx = max(arr[l],left_mx);
                result += (left_mx-arr[l]);
                l++;
            }
            else{
                right_mx = max(arr[r],right_mx);
                result += (right_mx-arr[r]);
                r--;
            }
        }
        return result;
    }
};