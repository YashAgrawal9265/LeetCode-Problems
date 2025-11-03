class Allocator {
public:
vector<int> arr;
unordered_map<int,vector<int>> mp; // {id,first index}
int n;
public:
    Allocator(int n) {
        arr.resize(n,-1);
        mp.clear();
        this->n = n;
    }
    
    int allocate(int size, int mId) {
        if(size > n) return -1;
        int st = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i] != -1){
                cnt = 0;
                st = i+1;
            }
            if(arr[i] == -1){
                cnt++;
            }
            if(cnt == size) break;
        }
        if(cnt == size and st < n){
            for(int i=st;i<st + size;i++){
                if(i < n) arr[i] = mId;
            }
            mp[mId].push_back(st);
            return st;
        }
        return -1;
        
    }
    
    int freeMemory(int mId) {
        if(mp.find(mId) == mp.end()) return 0;
        int cnt = 0;
        for(auto it: mp[mId]){
            int st = it;
            while(st < n and arr[st] == mId){
                arr[st] = -1;
                st++;
                cnt++;
            }
        }
        mp.erase(mId);
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */