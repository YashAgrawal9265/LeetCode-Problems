class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        int mnIdx = 0, mxIdx = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < mini){
                mnIdx = i;
                mini = nums[i];
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                mxIdx = i;
            }
        }
    
        int result = 0;
        if(mnIdx <= mxIdx){
            result += (mnIdx+1);
            result += (n-mxIdx);
        }
        else{
            result += (mxIdx + 1);
            result += (n-mnIdx);
        }
        
        
        // removing from front;
        int x = max(mxIdx+1,mnIdx+1);
        result = min(result,x);
        x = max(n-mxIdx,n-mnIdx);
        result = min(result,x);
        return result;
        
    }
};