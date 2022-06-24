class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> result(n,0);
        unordered_map<int,pair<int,long long>> mp;
        for(int i=0;i<n;i++){
            int count = mp[arr[i]].first;
            long long sum = mp[arr[i]].second;
            result[i] = 1LL*count*i - sum;
            mp[arr[i]].first++;
            mp[arr[i]].second += i;
            
        }
        
        mp.clear();
        for(int i=n-1;i>=0;i--){
            int count = mp[arr[i]].first;
            long long sum = mp[arr[i]].second;
            result[i] += sum - 1LL*count*i;
            mp[arr[i]].first++;
            mp[arr[i]].second += i;
        }
        return result;
        
    }
};