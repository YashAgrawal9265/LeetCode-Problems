class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n,0),right(n,0);
        left[0] = arr[0], right[n-1] = arr[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1],arr[i]);
            right[n-1-i] = max(right[n-1-i+1],arr[n-1-i]);
        }
        int result = 0;
        for(int i=0;i<n;i++){
            int mini = min(left[i],right[i]);
            if(mini > arr[i]) result += (mini - arr[i]);
        }
        return result;
    }
};