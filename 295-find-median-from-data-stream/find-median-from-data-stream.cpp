class MedianFinder {
priority_queue<int> mxHeap;
priority_queue<int,vector<int>,greater<int>> mnHeap;
public:
    MedianFinder() {
        while(!mxHeap.empty()) mxHeap.pop();

        while(!mnHeap.empty()) mnHeap.pop();
    }
    
    void addNum(int num) {
        
        if(mxHeap.empty() || num <= mxHeap.top()) mxHeap.push(num);
        else mnHeap.push(num);
        
        if((int)mxHeap.size() - (int)mnHeap.size()> 1){
           
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }
        
        if((int)mnHeap.size() - (int)mxHeap.size() > 0){
            
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }
    }
    
    double findMedian() {
        if((mnHeap.size() + mxHeap.size())&1) return mxHeap.top();
        return (mnHeap.top() + mxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */