class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> result;
        vector<pair<int,int>> temp(n);
        for(int i=0;i<n;i++){
            temp[i] = {abs(arr[i]-x),i};
            
        }
        sort(temp.begin(),temp.end());
        int i=0;
        while(k--){
            result.push_back(arr[temp[i++].second]);
        }
        sort(result.begin(),result.end());
        return result;
    }
};