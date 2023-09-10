class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                long long sum = target - 1LL*nums[i] - 1LL*nums[j];
                int left = j+1, right = n-1;
                while(left < right){
                    if(nums[left] + nums[right] > sum){
                        right--;
                    }
                    else if(nums[left] + nums[right] < sum){
                        left++;
                    }
                    else{
                        vector<int> temp(4);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        result.push_back(temp);
                        left++;
                        right--;
                        while(left < right and nums[left] == nums[left-1]) left++;
                        while(left < right and nums[right] == nums[right+1]) right--;
                    }
                }
                while(j <= n-3 and nums[j+1] == nums[j]) j++;
            }
            while(i <= n-4 and nums[i+1] == nums[i]) i++;
        }
        return result;
    }
};