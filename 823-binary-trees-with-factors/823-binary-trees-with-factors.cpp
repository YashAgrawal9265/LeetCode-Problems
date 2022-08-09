class Solution {
public:
    int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<long long, long long> mp;
        long long result = 0;
        for(int i=0;i<n;i++){
            mp[arr[i]] = 1;
            long long count = 0;
            for(int j=0;j<i;j++){
                if(arr[i] % arr[j] == 0){
                    count = (count + (mp[arr[j]] * mp[arr[i]/arr[j]])) % mod;
                }
            }
            mp[arr[i]] += count;
            result = (result +  mp[arr[i]]) % mod;
        }
        return result;
    }
};