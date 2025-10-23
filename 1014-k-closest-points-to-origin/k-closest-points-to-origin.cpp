class Solution {
public:
    int EucDist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    int quickSelect(vector<vector<int>>& arr, int l, int r, int k){
        int i = l, j = l;
        int pivot = EucDist(arr[r]);
        while(j < r){
            if(EucDist(arr[j]) <= pivot){
                swap(arr[i],arr[j]);
                i++;
            }
            j++;
        }
        swap(arr[i],arr[r]);
        if(i < k) return quickSelect(arr,i+1,r,k);
        else if(i > k) return quickSelect(arr,l,i-1,k);
        return i;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        if(arr.size() == k) return arr;
        int i = quickSelect(arr,0,arr.size() - 1, k);
        vector<vector<int>> result;
        for(int j=0;j<i;j++){
            result.push_back(arr[j]);
        }
        return result;
    }
};