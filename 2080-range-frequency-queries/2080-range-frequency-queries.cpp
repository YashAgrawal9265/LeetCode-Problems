class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> mp;
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(mp[value].begin(),mp[value].end(),left) - mp[value].begin();
        int r = upper_bound(mp[value].begin(),mp[value].end(),right) - mp[value].begin();
        r--;
        return r - l + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */