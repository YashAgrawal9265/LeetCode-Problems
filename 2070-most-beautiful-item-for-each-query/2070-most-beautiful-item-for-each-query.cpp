class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(),items.end());
        vector<int> maxi(n,INT_MIN);
        maxi[0] = items[0][1];
        for(int i=1;i<n;i++){
            maxi[i] = max(maxi[i-1],items[i][1]);
            
        }
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int i=0;
        vector<int> result(q.size(),0);
        for(auto &it: q){
            int idx = it.second;
            int val = it.first;
            while(i<n and items[i][0] <= val) i++;
            if(i>0)
                result[idx] = maxi[i-1];
        }
        return result;
    }
};