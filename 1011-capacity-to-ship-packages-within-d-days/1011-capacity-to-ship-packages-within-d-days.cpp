class Solution {
private:
    bool isValid(vector<int>& arr, int weight, int days){
        int totWeight = 0;
        for(int i=0;i<arr.size();i++){
            totWeight += arr[i];
            if(totWeight > weight){
                totWeight = arr[i];
                days--;
            }
            
        }
        if(totWeight <= weight) days--;
        if(days >= 0) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& arr, int days) {
        
        int totSum = 0;
        int maxi = INT_MIN;
        for(auto it: arr){
            totSum += it;
            maxi = max(maxi,it);
        }
        int low = maxi, high = totSum;
        while(high - low > 1){
            int mid = (low + high) >> 1;
            if(isValid(arr,mid,days)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        if(isValid(arr,low,days)) return low;
        return high;
    }
};