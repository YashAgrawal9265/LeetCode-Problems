class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(auto it: operations){
            int x = it[0], y = it[1];
            int idx = mp[x];
            nums[idx] = y;
            mp[y] = idx;
        }
        return nums;
    }
};