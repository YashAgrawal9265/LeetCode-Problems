class Vector2D {
public:
    vector<vector<int>> arr;
    int i = 0;
    int j = 0;
    Vector2D(vector<vector<int>>& vec) {
        arr = vec;
    }
    void solve(){
        while(i < arr.size() and j == arr[i].size()){
            i++;
            j = 0;
        }
    }
    int next() {
        if(!hasNext()) return -1;
        return arr[i][j++];
    }
    
    bool hasNext() {
        solve();
        return i < arr.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */