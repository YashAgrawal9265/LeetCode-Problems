class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> greater(n,1), smaller(n,1);
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                greater[i] = 1 + smaller[i-1];
                smaller[i] = smaller[i-1];
            }
            else if(nums[i] < nums[i-1]){
                smaller[i] = 1 + greater[i-1];
                greater[i] = greater[i-1];
            }
            else{
                smaller[i] = smaller[i-1];
                greater[i] = greater[i-1];
            }
        }
        return max(smaller[n-1],greater[n-1]);
    }
};