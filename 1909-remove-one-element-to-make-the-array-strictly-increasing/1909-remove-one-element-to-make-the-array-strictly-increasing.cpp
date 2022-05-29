class Solution {
public:
    bool isValid(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
    bool canBeIncreasing(vector<int>& nums) {
        int i = 0;
        for(auto it =  nums.begin(); it != nums.end(); it++){
            int x = *it;
            nums.erase(it);
            if(isValid(nums)) return true;
            nums.insert(nums.begin()+i,x);
            i++;
        }
        return false;
    }
};