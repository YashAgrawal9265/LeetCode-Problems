class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // {number, idx}
        deque<pair<int,int>> dq;
        vector<int> result;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            while(dq.size() > 0 and nums[i] >= dq.back().first) dq.pop_back();
            dq.push_back({nums[i],i});
            maxi = max(maxi,nums[i]);
            if(dq.front().second <= i-k){
                if(maxi == dq.front().first){
                    maxi = INT_MIN;
                }
                dq.pop_front();
                maxi = max(maxi,dq.front().first);
            }
            if(i >= k-1){
                result.push_back(maxi);
            }
        }
        return result;
    }
};