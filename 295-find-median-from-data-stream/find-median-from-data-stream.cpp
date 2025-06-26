class MedianFinder {
public:
    // minHeap
    priority_queue<int,vector<int>,greater<int>> mnHeap;

    // maxHeap
    priority_queue<int> mxHeap;
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        if(mxHeap.empty() || num < mxHeap.top()){
            mxHeap.push(num);
        }
        else{
            mnHeap.push(num);
        }

        if(mxHeap.size() > mnHeap.size() + 1){
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        else if(mnHeap.size() > mxHeap.size() + 1){
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }
    
    double findMedian() {
        if(mxHeap.size() == mnHeap.size()){
            return double(mxHeap.top() + mnHeap.top())/2.0;
        }
        else{
            if(mxHeap.size() > mnHeap.size()) return mxHeap.top();
            else return mnHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */