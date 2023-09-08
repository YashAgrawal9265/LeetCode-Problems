class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int negIdx = 1, posIdx = 0;
        for(auto it: nums){
            if(it >= 0){
                result[posIdx] = it;
                posIdx += 2;
            }
            else{
                result[negIdx] = it;
                negIdx += 2;
            }
        }
        return result;
    }
};