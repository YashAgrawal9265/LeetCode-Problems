class Solution {
public:
    
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        int mxIdx = 0;
        priority_queue<int> pq;
        for(int i=0;i<target.size();i++){
            sum += target[i];
            pq.push(target[i]);
        }
        while(!pq.empty() and pq.top() != 1){
            int val = pq.top();
            pq.pop();
            long long diff = sum - val;
            if(val == 1 || diff == 1) return true;
            if(val <= diff || diff == 0 || val % diff == 0) return false;
            val %= diff;
            pq.push(val);
            sum = diff + val;
        }
        return true;
    }
};