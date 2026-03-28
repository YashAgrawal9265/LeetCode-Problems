class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int k) {
        if(arr.size() % k != 0) return false;
        unordered_map<int,int> mp;
        for(auto it: arr) mp[it]++;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it: mp) pq.push(it.first);
        while(!pq.empty()){
            int first = pq.top();
            // cout<<"first: "<<first<<endl;
            for(int i=first;i<first+k;i++){
                if(mp[i] == 0) return false;
                // cout<<i<<" ";
                mp[i]--;
                if(mp[i] == 0){
                    // cout<<i<<" "<<pq.top()<<endl;
                    if(pq.top() == i){
                        pq.pop();
                    }
                        
                }
            }
        }
        return true;
    }
};