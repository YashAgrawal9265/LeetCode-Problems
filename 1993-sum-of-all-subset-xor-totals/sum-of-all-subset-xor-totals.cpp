class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& temp){
        if(idx < 0){  
            int x = 0;  
            for(auto it: temp){
                x ^= it;
            }
            return x;
        }
        temp.push_back(nums[idx]);
        int pick = solve(nums,idx-1,temp);
        temp.pop_back();
        int nopick = solve(nums,idx-1,temp);
        return pick + nopick;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        return solve(nums,n-1,temp);

    }
};