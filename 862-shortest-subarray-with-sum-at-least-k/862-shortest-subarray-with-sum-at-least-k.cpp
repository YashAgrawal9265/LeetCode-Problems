class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long,int>> dq;
        int n = nums.size();
        long sum = 0;
        int mnLen = n + 1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum >= k){
                mnLen = min(mnLen,i+1);
            }
            while(!dq.empty() and sum - dq.front().first >= k){
                mnLen = min(mnLen,i-dq.front().second);
                dq.pop_front();
            }
            while(!dq.empty() and sum <= dq.back().first){
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        return mnLen == n + 1 ? -1 : mnLen;
    }
};