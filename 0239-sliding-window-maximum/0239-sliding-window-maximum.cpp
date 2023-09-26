class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq;
        vector<int> result;
        for(int i=0;i<n;i++){
            while(!dq.empty() and dq.back().first <= nums[i]) dq.pop_back();
            dq.push_back({nums[i],i});
            if(!dq.empty() and i-k >= dq.front().second) dq.pop_front();
            if(i >= k-1) result.push_back(dq.front().first);
        }
        return result;
    }
};