class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto &it: nums){
            mp[it]++;
        }
        vector<pair<int,int>> temp;
        for(auto &it: mp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),cmp);
        vector<int> result;
        for(auto &it: temp){
            int i = 0;
            while(i < it.first){
                result.push_back(it.second);
                i++;
            }
        }
        return result;
    }
};