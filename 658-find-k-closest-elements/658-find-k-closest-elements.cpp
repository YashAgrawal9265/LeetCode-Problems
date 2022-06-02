struct cmp{
    bool operator()(pair<int,int>& a, pair<int,int>& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        // max-heap
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        
        for(int i=0;i<n;i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        sort(result.begin(),result.end());
        return result;
    }
};