class Solution {
private:
    int lis(vector<int> & arr){
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
      
        for(int i=1;i<n;i++){
            if(arr[i] >= temp.back()) temp.push_back(arr[i]);
            else{
                int idx = upper_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }
        return temp.size();
    }
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int result = 0;
        for(int i=0;i<k;i++){
            vector<int> sbarr;
            for(int j=i;j<n;j+=k){
                sbarr.push_back(arr[j]);
            }
            result += sbarr.size() - lis(sbarr);
        }
        return result;
    }
};