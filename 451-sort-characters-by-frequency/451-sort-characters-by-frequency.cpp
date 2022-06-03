class Solution {
public:
    string frequencySort(string str) {
        int n = str.size();
        unordered_map<char,int> mp;
        for(auto &it: str){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it:mp){
            pq.push({it.second,it.first});
        }
        string result;
        while(!pq.empty()){
            int i = 0;
            while(i<pq.top().first){
                result.push_back(pq.top().second);
                i++;
            }
            pq.pop();
        }
        return result;
    }
};