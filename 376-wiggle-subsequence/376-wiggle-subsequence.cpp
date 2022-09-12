class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int mxLen = 1;
        vector<int> greater(n,1),smaller(n,1);
        for(int i=1;i<n;i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]){
                    greater[i] = max(greater[i],smaller[prev]+1);
                }
                else if(nums[i] < nums[prev]){
                    smaller[i] = max(smaller[i],greater[prev]+1);
                }
            }
            mxLen = max(greater[i],smaller[i]);
        }
        return mxLen;
    }
};