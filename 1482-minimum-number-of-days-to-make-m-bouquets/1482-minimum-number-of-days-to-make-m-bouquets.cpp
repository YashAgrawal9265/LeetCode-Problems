class Solution {
private:
    bool isValid(vector<int>& arr, int days, int boquet, int flower){
        int x = flower;
        for(int i=0;i<arr.size();i++){
            if(arr[i] <= days){
                x--;
                if(x == 0){
                    boquet--;
                    x = flower;
                }
            }
            else{
                x = flower;
            }
            if(boquet == 0) return true;
        }
        
        return false;
    }
public:
    int minDays(vector<int>& arr, int m, int k) {
        if(1LL*m*k > arr.size()) return -1;
        int low = 1, high = *max_element(arr.begin(),arr.end());
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(arr,mid,m,k)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(isValid(arr,low,m,k)) return low;
        return high;
        
    }
};