class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            // left area is sorted
            if(arr[low] <= arr[mid]){
                if(target >= arr[low] and target <= arr[mid]){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            // right area is sorted
            else{
                if(target >= arr[mid] and target <= arr[high]){
                    low = mid;
                }
                else{
                    high = mid-1;
                }
            }
        }
        if(arr[low] == target) return low;
        if(arr[high] == target) return high;
        return -1;
    }
};