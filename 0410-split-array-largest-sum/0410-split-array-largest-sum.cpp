class Solution {
private:
    bool isValid(vector<int>& arr, int totSum, int k){
        int sum = 0;
        for(auto it: arr){
            sum += it;
            if(sum > totSum){
                sum = it;
                k--;
            }
        }
        if(sum <= totSum) k--;
        if(k < 0) return false;
        return true;
    }
public:
    int splitArray(vector<int>& arr, int k) {
        int low = INT_MIN, high = 0;
        for(auto it: arr){
            low = max(low,it);
            high += it;
        }
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(arr,mid,k)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        if(isValid(arr,low,k)) return low;
        return high;
    }
};