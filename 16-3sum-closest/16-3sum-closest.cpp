class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int delta = INT_MAX;
        int ans;
        for(int i=0;i<n-2;i++){
            int left = i+1, right = n-1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < delta){
                   
                    delta = abs(sum - target);
                    ans = sum;
                }
                
                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    // if nums[i] + nums[left] + nums[right] == target
                    return target;
                }
                  
            }
        }
        return ans;
    }
};