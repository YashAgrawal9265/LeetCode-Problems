class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n,1);
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                temp[i] = 1 + temp[i-1];
            }
        }
        int result = temp[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1] and temp[i] <= temp[i+1]){
                temp[i] = 1 + temp[i+1];
            }
            result += temp[i];
        }
        return result;
        
    }
};