class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int windowSize = n - k;
        int totSum = 0;
        for(auto it: arr) totSum += it;
        int mnSum = INT_MAX;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(i >= windowSize){
                sum -= arr[i-windowSize];
            }
            if(i >= windowSize-1){
                mnSum = min(mnSum,sum);
            }
        }
        return totSum - mnSum;
    }
};