class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, h = n-1;
        while(h - l  > 1){
            int mid = (l + h) >> 1;
            if(arr[l] <= arr[mid]){
                if(target >= arr[l] and target <= arr[mid]){
                    h = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{ // right side is sorted
                if(target >= arr[mid] and target <= arr[h]){
                    l = mid;
                }
                else{
                    h = mid-1;
                }
            }
        }
        if(arr[l] == target) return l;
        if(arr[h] == target) return h;
        return -1;
    }
};