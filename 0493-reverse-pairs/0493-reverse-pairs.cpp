class Solution {
private:
    int merge(vector<int>& arr, int left, int mid, int right){
        vector<int> temp;
        int i = left, j = mid+1;
        int count = 0;
        
        for(i=left;i<=mid;i++){
            while(j <= right and 1LL*arr[i] > 1LL*2*arr[j]){
                count += (mid-i+1);
                j++;
            }
        }
        i = left, j = mid+1;
        while(i <= mid and j <= right){
            if(arr[i] < arr[j]){
                temp.push_back(arr[i++]);
            }
            else{
                temp.push_back(arr[j++]);
            }
        }
        while(i <= mid) temp.push_back(arr[i++]);
        while(j <= right) temp.push_back(arr[j++]);
        for(int i=left;i<=right;i++){
            arr[i] = temp[i-left];
        }
        return count;
    }
    int mergeSort(vector<int>& arr, int left, int right){
        int count = 0;
        if(left < right){
            int mid = (left + right) >> 1;
            count += mergeSort(arr,left,mid);
            count += mergeSort(arr,mid+1,right);
            count += merge(arr,left,mid,right);
        }
        return count;
    }
public:
    int reversePairs(vector<int>& arr) {
        int n = arr.size();
        
        return mergeSort(arr,0,n-1);
    }
};