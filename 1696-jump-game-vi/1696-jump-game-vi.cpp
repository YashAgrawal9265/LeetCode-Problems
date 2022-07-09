class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        pq.push({nums[n-1],n-1});
        int curScore = nums[n-1];
        for(int idx=n-2;idx>=0;idx--){
            while(pq.top().second - idx > k) pq.pop();
            int maxi = pq.top().first;
            curScore = nums[idx] + maxi;
            pq.push({curScore,idx});
        }
        return curScore;
    }
};