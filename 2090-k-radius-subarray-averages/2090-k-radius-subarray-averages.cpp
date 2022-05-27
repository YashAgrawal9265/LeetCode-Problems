class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n,-1);
        long long sum = 0;
        int idx = k;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(i>=2*k){
                result[idx++] = sum / (2*k+1);
                sum -= nums[i - 2*k];
            }
        }
        return result;
    }
};