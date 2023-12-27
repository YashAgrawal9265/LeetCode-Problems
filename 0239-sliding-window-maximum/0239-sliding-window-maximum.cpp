class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result;
        deque<int> dq;
        for(int i=0;i<n;i++){
            while(!dq.empty() and arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            while(i-dq.front() >= k) dq.pop_front();
            if(i >= k-1) result.push_back(arr[dq.front()]);
        }
        return result;
    }
};