class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;
    int upper_bound(vector<pair<int,string>>& arr, int key){
        int l = 0, h = arr.size() - 1;
        while(h - l > 1){
            int mid = (l + h) >> 1;
            if(arr[mid].first > key){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(arr[l].first > key) return l;
        if(arr[h].first > key) return h;
        return arr.size();
    }
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(mp.find(key) == mp.end()) return "";
        int idx = upper_bound(mp[key],timestamp);
        idx--;
        if(idx >= 0 and idx < mp[key].size()) ans = mp[key][idx].second;
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */