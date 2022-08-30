class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for(int i=0;i<n;i++){
            
            while(!pq.empty() and i - k >= pq.top().second) pq.pop();
            pq.push({nums[i],i});
            if(i >= k-1) result.push_back(pq.top().first);
        }
        return result;

    }
};