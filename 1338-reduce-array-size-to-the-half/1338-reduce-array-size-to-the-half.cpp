class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n =arr.size();
        unordered_map<int,int> mp;
        for(auto it: arr) mp[it]++;
        priority_queue<int> pq;
        for(auto it: mp){
            pq.push(it.second);
        }
        int x= 0;
        int count = 0;
        while(x < n/2){
            x += pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};