class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<pair<int,int>> temp;
        for(auto it: mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        int idx = 0;
        vector<int> result;
        while(k--){
            result.push_back(temp[idx++].second);
        }
        return result;
    }
    
};