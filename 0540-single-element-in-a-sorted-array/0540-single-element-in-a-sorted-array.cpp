class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int low = 1, high = n-2;
        while(high-low > 1){
            int mid = (low + high) >> 1;
            if(((mid&1) and arr[mid-1] == arr[mid]) or (!(mid&1) and arr[mid+1] == arr[mid])){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(arr[low] != arr[low+1] and arr[low] != arr[low-1]) return arr[low];
        if(arr[high] != arr[high+1] and arr[high] != arr[high-1]) return arr[high];
        return -1;
    }
};