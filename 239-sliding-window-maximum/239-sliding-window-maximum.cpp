class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        int right = 0;
        while(right < n){
            while(!dq.empty() and nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
            if(right - dq.front() >= k) dq.pop_front();
            if(right >= k-1) result.push_back(nums[dq.front()]);
            right++;
        }
        return result;
    }
};