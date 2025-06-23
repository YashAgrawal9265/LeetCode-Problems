struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};