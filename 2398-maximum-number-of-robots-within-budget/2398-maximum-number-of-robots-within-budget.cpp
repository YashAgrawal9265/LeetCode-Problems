class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int left = 0, right = 0;
        deque<int> dq;
        long long sum = 0;
        int maxi = 0;
        while(right < n){
            while(!dq.empty() and dq.back() < chargeTimes[right]){
                dq.pop_back();
            }
            dq.push_back(chargeTimes[right]);
            sum += runningCosts[right];
            while(1LL*dq.front() + (right-left+1)*sum > budget){
                sum -= runningCosts[left];
                if(chargeTimes[left] == dq.front()) dq.pop_front();
                left++;
            }
            maxi = max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};