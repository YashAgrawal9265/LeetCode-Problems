class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> dq;
        int curScore = 0;
        for(int idx=n-1;idx>=0;idx--){
            if(!dq.empty() and dq.front().second - idx > k) dq.pop_front();
            curScore = nums[idx];
            if(!dq.empty()) curScore += dq.front().first;
            while(!dq.empty() and dq.back().first < curScore){
                dq.pop_back();
            }
            dq.push_back({curScore,idx});
        }
        return curScore;
    }
};