class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        while(n != 1){
           
            int minVal = INT_MAX;
            int minIdx;
            vector<int>::iterator minPtr;
            int idx = 0;
            for(auto it = arr.begin(); it != arr.end(); it++){
                if(*it < minVal){
                    minIdx = idx;
                    minVal = *it;
                    minPtr = it;
                }
                idx++;
            }
            // cout<<minVal<<endl;
            if(minIdx > 0 and minIdx < n-1) res += (minVal*(min(arr[minIdx-1],arr[minIdx+1])));
            else if(minIdx == 0) res += (minVal*arr[minIdx+1]);
            else{
                res += (minVal*arr[minIdx-1]);
            }
            
            n--;
            arr.erase(minPtr);
        }
        return res;
    }
};