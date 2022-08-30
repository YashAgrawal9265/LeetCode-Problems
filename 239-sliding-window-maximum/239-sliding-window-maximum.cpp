class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        int right = 0, left = 0;
        while(right < n){
            while(!dq.empty() and dq.back() < nums[right]) dq.pop_back();
            dq.push_back(nums[right]);
            if(right >= k){
                if(dq.front() == nums[left]) dq.pop_front();
                left++;
               
            }
            if(right >= k-1) result.push_back(dq.front());
            right++;
        }
        return result;
        
    }
};