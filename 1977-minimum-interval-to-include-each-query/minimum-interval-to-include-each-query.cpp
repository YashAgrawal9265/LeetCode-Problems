class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& arr, vector<int>& queries) {
        int n = queries.size();
        vector<int> result(n,0);
        sort(arr.begin(),arr.end());
        vector<pair<int,int>> q;
        for(int i=0;i<n;i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int j = 0;
        for(int i=0;i<q.size();i++){
            while(j < arr.size() and q[i].first >= arr[j][0]){
                pq.push({arr[j][1] - arr[j][0] + 1, arr[j][1]});
                j++;
            }  

            // poping element which are not needed in min heap
            while(!pq.empty() and pq.top().second < q[i].first) pq.pop();

            int dist = -1;
            if(!pq.empty()) dist = pq.top().first;
            result[q[i].second] = dist;
        }
        return result;
    }
};