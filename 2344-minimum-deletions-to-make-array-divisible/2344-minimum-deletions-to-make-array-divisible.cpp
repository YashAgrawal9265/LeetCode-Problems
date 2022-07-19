class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& div) {
        sort(nums.begin(),nums.end());
        int n = div.size();
        int gcd = 0;
        for(auto it: div) gcd = __gcd(gcd,it);
        int result = -1;
        for(int i=0;i<nums.size();i++){
            if(gcd % nums[i] == 0){
                result = i;
                break;
            }
        }
        return result;
    }
};