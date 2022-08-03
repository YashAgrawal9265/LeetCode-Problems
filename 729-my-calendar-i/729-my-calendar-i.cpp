class MyCalendar {
private:
    map<int,int> mp;
public:
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        auto it =  mp.upper_bound(start);
        if(it == mp.end() or end <= it->second){
            mp[end] = start;
            return true;
        }
        return false;
    }
};