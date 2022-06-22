class Solution {
public:
    int partition(vector<int>& arr, int l, int r){
        int pivot = arr[r];
        int i = l, j = l;
        while(j < r){
            if(arr[j] <= pivot){
                swap(arr[i],arr[j]);
                i++,j++;
            }
            else{
                j++;
            }
        }
        swap(arr[i],arr[r]);
        return i;
    }
    void solve(vector<int>& arr, int l ,int r, int k, int& result){
        if(l <= r){
            int p = partition(arr,l,r);
            if(p == arr.size() - k){
                result = arr[p];
                return;
            }
            solve(arr,l,p-1,k,result);
            solve(arr,p+1,r,k,result);
        }
    }
    int findKthLargest(vector<int>& arr, int k) {
        int result = 0;
        solve(arr,0,arr.size()-1,k,result);
        return result;
    }
};