class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele = -1, count = 0;
        for(int i=0;i<n;i++){
            if(count == 0){
                ele = nums[i];
                count = 1;
            }
            else if(nums[i] == ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};