class Vector2D {
public:
    vector<int> arr;
    int i;
    int size = 0;
    Vector2D(vector<vector<int>>& vec) {
        for(auto it: vec){
            for(auto i: it) arr.push_back(i);
        }
        i = 0;
        size = arr.size();
    }
    
    int next() {
        return arr[i++];
    }
    
    bool hasNext() {
        return i < size;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */