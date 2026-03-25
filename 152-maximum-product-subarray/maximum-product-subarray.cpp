class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int prefix = 0, suffix =0, maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= arr[i];
            suffix *= arr[n-i-1];
            maxi = max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};