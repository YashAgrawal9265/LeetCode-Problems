class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];
        int l = 1, h = n-2;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(mid&1){
                if(arr[mid] == arr[mid+1]){
                    h = mid-1;
                }
                else{
                    l = mid;
                }
            }
            else{
                if(arr[mid] == arr[mid+1]){
                    l = mid+1;
                }
                else{
                    h = mid;
                }
            }
        }
        // cout<<l<<" "<<h<<endl;
        if(arr[l] != arr[l-1] and arr[l] != arr[l+1]) return arr[l];
        if(arr[h] != arr[h-1] and arr[h] != arr[h+1]) return arr[h];
        return -1;
    }
};