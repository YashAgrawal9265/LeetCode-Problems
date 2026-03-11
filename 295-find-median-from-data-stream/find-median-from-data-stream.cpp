class MedianFinder {
public:
    priority_queue<int> mxHeap;
    priority_queue<int,vector<int>,greater<int>> mnHeap;
    MedianFinder() {
        while(mxHeap.size() > 0) mxHeap.pop();
        while(mnHeap.size() > 0) mnHeap.pop();
    }
    
    void addNum(int num) {
        
        if(mxHeap.size() > 0 and num < mxHeap.top()) mxHeap.push(num);
        else mnHeap.push(num);
        
        if(int(mxHeap.size() - mnHeap.size()) > 1){
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        else if(int(mnHeap.size() - mxHeap.size()) > 1){
            
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
        
    }
    
    double findMedian() {
       
        if((mxHeap.size() + mnHeap.size()) % 2 == 0){
            return (mxHeap.top() + mnHeap.top()) / 2.0;
        }
        else{
            if(mnHeap.size() > mxHeap.size()) return mnHeap.top() / 1.0;
            else return mxHeap.top() / 1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */