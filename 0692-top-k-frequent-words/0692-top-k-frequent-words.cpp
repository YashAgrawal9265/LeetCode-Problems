struct cmp{
    bool operator()(pair<int,string>& a, pair<int,string>& b){
        
        if(a.first > b.first) return true;
        else if(a.first == b.first){
            if(a.second < b.second) return true;
            else return false;
        }
        return false;
       
    }
    
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it: words) mp[it]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto it: mp){
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> result(k);
        k--;
        while(!pq.empty()){
            result[k--] = pq.top().second;
            pq.pop();
        }
        return result;
    }
};