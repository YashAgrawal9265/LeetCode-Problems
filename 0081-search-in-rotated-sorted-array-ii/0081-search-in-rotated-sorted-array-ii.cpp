class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(arr[mid] == arr[low] and arr[mid] == arr[high]){
                // reducing the search space
                low++;
                high--;
            }
            // left half is sorted
            else if(arr[low] <= arr[mid]){
                if(target >= arr[low] and target <= arr[mid]){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            // right half is sorted
            else{
                if(target >= arr[mid] and target <= arr[high]){
                    low = mid;
                }
                else{
                    high = mid-1;
                }
            }
        }
        if(arr[low] == target) return true;
        if(arr[high] == target) return true;
        return false;
    }
};