class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n = arr.size();
        vector<int> greater(n,1), smaller(n,1);
        int result = 1;
        for(int i=1;i<n;i++){
            for(int prev = 0; prev < i; prev++){
                if(arr[i] > arr[prev]){
                    greater[i] = max(greater[i],1+smaller[prev]);
                }
                else if(arr[i] < arr[prev]){
                    smaller[i] = max(smaller[i],1+greater[prev]);
                }
            }
            result = max(smaller[i],greater[i]);
        }
        
        return result;
    }
};