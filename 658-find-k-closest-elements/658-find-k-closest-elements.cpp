class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int low = 0, high = n-1;
        while(high - low > 1){
            int mid = (high + low) >> 1;
            if(arr[mid] <= x) low = mid;
            else high = mid;
        }  
        int closestIdx;
        if(arr[low] == x) closestIdx = low;
        else if(arr[high] == x) closestIdx = high;
        else{
            if(abs(arr[low]-x) <= abs(arr[high] - x)){
                closestIdx = low;
            }
            else{
                closestIdx = high;
            }
        }
        k--;
        int left = closestIdx-1, right = closestIdx+1;
        while(k > 0){
            if(left < 0) right++;
            else if(right >= n) left--;
            else if(abs(arr[left]-x) <= abs(arr[right]-x)) left--;
            else right++;
            k--;
        }
        vector<int> result;
        for(int i=left+1;i<right;i++){
            result.push_back(arr[i]);
        }
        return result;
    }
};