class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it: tasks){
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        int time = 0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            time += 1;
            if(!pq.empty()){
                int curFreq = pq.top() - 1;
                pq.pop();
                if(curFreq > 0){
                    q.push({curFreq,time+n});
                }
            }
            if(!q.empty()){
                while(!q.empty() and q.front().second <= time){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
        }
        return time;

    }
};