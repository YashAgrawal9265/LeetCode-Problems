class Solution {
private:
    int countSubArr(vector<int>& arr, int target){
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            if(sum == target) count++;
            if(mp.find(sum - target) != mp.end()){
                count += mp[sum-target];
            }
            mp[sum]++;
        }
        return count;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();
        int count = 0;
        for(int row = 0;row<m;row++){
            vector<int> arr(n,0);
            for(int i=row;i<m;i++){
                for(int j=0;j<n;j++){
                    arr[j] += mat[i][j];
                }
                count += countSubArr(arr,target);
            }
        }
        return count;
    }
};