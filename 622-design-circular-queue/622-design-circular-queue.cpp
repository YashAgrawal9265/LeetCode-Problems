class MyCircularQueue {
private:
    int front, rear, size, mxSize;
    int *arr;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        size = 0;
        mxSize = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        size++;
        rear = (rear+1) % mxSize;
        arr[rear] = value;
        if(size == 1) front++;
        return true;
        
    }
    bool deQueue() {
        if(isEmpty()) return false;
        size--;
        if(size == 0){
            front = -1;
            rear = -1;
        }
        else front = (front+1)%mxSize;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(size == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(size == mxSize) return true;
        return false;
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