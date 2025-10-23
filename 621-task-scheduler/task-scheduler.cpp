class Solution {
public:
    int leastInterval(vector<char>& arr, int n) {
        priority_queue<int> pq;
        unordered_map<char,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
           
            pq.push(it.second);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() or !q.empty()){
            time++;
            if(!pq.empty()){
                int curFreq = pq.top() - 1;

                pq.pop();
                if(curFreq > 0){
                    q.push({curFreq,time + n});
                }
            }
            if(!q.empty() and q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
        
    }
};