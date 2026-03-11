class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>> arr;
        for(int i=0;i<tasks.size();i++){
            arr.push_back({tasks[i][0], {tasks[i][1],i}});
        }
        sort(arr.begin(),arr.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result;
        int i=0;
        long time = arr[0].first;
        while(i < arr.size() || !pq.empty()){
            while(i < arr.size() and time >= arr[i].first){
                // cout<<time<<" "<<arr[i].first<<" "<<arr[i].second.second<<endl;
                pq.push({arr[i].second.first,arr[i].second.second});
                i++;
            }
            if(pq.empty()){
                time = arr[i].first;
            }
            else{
                 pair<int,int> process = pq.top();
                pq.pop();
                result.push_back(process.second);
                time += process.first;
            }
           
        }
        return result;
    }
};