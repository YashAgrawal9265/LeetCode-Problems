class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) {
        int count = 0;
        int maxi;
        for(int i=lower;i<=upper;i++){
            bool flag = true;
            int x = i;
            maxi = i;
            for(int j=0;j<arr.size();j++){
                if(x + arr[j] < lower || x + arr[j] > upper){
                    flag = false;
                    break;
                }
                x = x + arr[j];
                maxi = max(maxi,x);
            }
            if(flag){
                return upper - maxi + 1;
            }
        }
        // cout<<maxi<<endl;
        return 0;
    }
};