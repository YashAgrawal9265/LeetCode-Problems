class NumberContainers {
private:
    unordered_map<int,int> mp1;
    map<int,set<int>> mp2;
public:
    NumberContainers() {
        mp1.clear();
        mp2.clear();
    }
    
    void change(int idx, int n) {
        if(mp1.find(idx) != mp1.end()){
            mp2[mp1[idx]].erase(idx);
            mp1[idx] = n;
            mp2[n].insert(idx);
        }
        else{
            mp1[idx] = n;
            mp2[n].insert(idx);
        }
        
    }
    
    int find(int n) {
        if(mp2[n].size() == 0){
            return -1;
        }
        return *mp2[n].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */