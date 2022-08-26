class Solution {
private:
    int merge(vector<int>& nums, int l, int mid, int h){
        int n1 = mid - l + 1;
        int n2 = h - mid;
        int arr1[n1], arr2[n2];
        for(int i=0;i<n1;i++) arr1[i] = nums[l+i];
        for(int i=0;i<n2;i++) arr2[i] = nums[mid+1+i];
        
        int i = 0, j = 0, count = 0;
        for(int i=0;i<n1;i++){
            while(j < n2 and 1LL*arr1[i] > 1LL*2*arr2[j]){
                count += (n1-i);
                j++;
            }
        }
        
        i = 0, j = 0;
        int k = l;
        while(i < n1 and j < n2){
            if(arr1[i] <= arr2[j]){
                nums[k++] = arr1[i++];
            }
            else{
                nums[k++] = arr2[j++];
            }
        }
        while(i < n1) nums[k++] = arr1[i++];
        while(j < n2) nums[k++] = arr2[j++];
        return count;
    }
    int mergeSort(vector<int>& nums, int l, int h){
        int count = 0;
        if(l < h){
            int mid = (l + h) >> 1;
            count += mergeSort(nums,l,mid);
            count += mergeSort(nums,mid+1,h);
            count += merge(nums,l,mid,h);
        }
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};