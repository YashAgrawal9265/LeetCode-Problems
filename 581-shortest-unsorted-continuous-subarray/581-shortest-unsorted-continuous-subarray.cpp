class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        int st = -1, en = -1;
        for(int i=0;i<temp.size();i++){
            if(temp[i] != nums[i]){
                if(st == -1) st = i;
                en = i;
            }
        }
        if(st == -1 and en == -1) return 0;
        return en - st + 1;
    }
};