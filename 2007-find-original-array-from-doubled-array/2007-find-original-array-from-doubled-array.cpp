class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        int n = changed.size();
        if(n&1) return {};
        unordered_map<int,int> mp;
        vector<int> result;
        for(auto it: changed) mp[it]++;
        for(auto it: changed){
            if(mp[it] <= 0) continue;
            mp[it]--;
            if(mp[it*2] > 0){
                result.push_back(it);
                mp[it*2]--;
            }
        }
        if(result.size() == n/2) return result;
        return {};
    }
};