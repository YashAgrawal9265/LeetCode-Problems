class DetectSquares {
public:
    // map<pair<int,int>,int> mp;
    unordered_map<long,int> mp;
    vector<pair<int,int>> arr;
    long getKey(int x, int y){
        return (((1LL*x) << 32) | (1LL*y));
    }
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        arr.push_back({point[0],point[1]});
        // mp[{point[0],point[1]}]++;
        mp[getKey(point[0],point[1])]++;
    }
    
    int count(vector<int> point) {
        int count  = 0;
        for(auto it: arr){
            int x = it.first, y = it.second;
            int px = point[0], py = point[1];
            if((abs(px - x) != abs(py - y) ) or (px == x and py == y)) continue;
            // int c1 = mp[{px,y}];
            int c1 = mp[getKey(px,y)];
            // int c2 = mp[{x,py}];
            int c2 = mp[getKey(x,py)];
            count += (c1*c2);
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */