class Solution {
private:
    void merge(vector<pair<int,int>>& arr, vector<int>& result, int l, int mid, int h){
        int n1 = mid - l + 1;
        int n2 = h - mid;
        pair<int,int> arr1[n1], arr2[n2];
        for(int i=0;i<n1;i++) arr1[i] = arr[l+i];
        for(int i=0;i<n2;i++) arr2[i] = arr[mid+1+i];
        int k = l, i = 0, j = 0;
        while(i < n1 and j < n2){
            if(arr1[i] > arr2[j]){
                int index = arr1[i].second;
                result[index] += (n2-j);
                arr[k++] = arr1[i++];
            }
            else{
                arr[k++] = arr2[j++];
            }
        }
        while(i < n1) arr[k++] = arr1[i++];
        while(j < n2) arr[k++] = arr2[j++];
    }
    void mergeSort(vector<pair<int,int>>& arr, vector<int>& result, int l, int h){
        if(l < h){
            int mid = (l + h) >> 1;
            mergeSort(arr,result,l,mid);
            mergeSort(arr,result,mid+1,h);
            merge(arr,result,l,mid,h);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        vector<int> result(n,0);
        mergeSort(arr,result,0,n-1);
        return result;
    }
};