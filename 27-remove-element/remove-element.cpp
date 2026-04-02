class Solution {
public:
    int removeElement(vector<int>& arr, int val) {
        int n = arr.size();
        int i = 0, j = n-1;
        while(i <= j){
            if(arr[j] == val){
                j--;
                continue;
            }
            if(arr[i] == val){
                swap(arr[i],arr[j]);
                j--;
            }
            i++;
        }
        return i;
    }
};