class MyCircularQueue {
private:
    int *arr;
    int front;
    int rear;
    int curSize;
    int mxSize;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        front = rear = -1;
        curSize = 0;
        mxSize = k;
    }
    
    bool enQueue(int value) {
        if(curSize >= mxSize) return false;
        if(curSize == 0){
            front = 0;
        }
        curSize++;
        rear = (rear + 1) % mxSize;
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(curSize == 0) return false;
        curSize--;
        if(curSize == 0){
            front = -1;
            rear = -1;
        }
        else front = (front + 1) % mxSize;
        return true;
    }
    
    int Front() {
        if(curSize == 0) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(curSize == 0) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return curSize == 0 ? true : false;
    }
    
    bool isFull() {
        return curSize == mxSize ? true : false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */