class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = potions.size();
        vector<int> result;
        for(auto it: spells){
            long long val = success / it;
            if(success % it != 0) val++;
            int idx = lower_bound(potions.begin(),potions.end(),val) - potions.begin();
            result.push_back(n - idx);
        }
        return result;
    }
};