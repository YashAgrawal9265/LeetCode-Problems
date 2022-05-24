class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        int n = arr.size();
        int time = 0;
        for(int i=0;i<n;i++){
            if(i <= k) time += min(arr[i],arr[k]);
            else time += min(arr[i],arr[k]-1);
        }
        return time;
    }
};