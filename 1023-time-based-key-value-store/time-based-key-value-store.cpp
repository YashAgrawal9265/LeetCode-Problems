class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        int low = 0, high = mp[key].size() - 1;
        while(high - low > 1){
            int mid = (low + high) / 2;
            if(mp[key][mid].first <= timestamp){
                low = mid;
            }
            else{
                high = mid - 1;
            }

        }
        if(mp[key][high].first <= timestamp) return mp[key][high].second;
        if(mp[key][low].first <= timestamp) return mp[key][low].second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */