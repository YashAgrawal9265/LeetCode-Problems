class MyCircularDeque {
private:
    int *arr;
    int front;
    int rear;
    int curSize;
    int mxSize;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        front = -1;
        rear = -1;
        curSize = 0;
        mxSize = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(curSize == 0){
            insertLast(value);
        }
        else{
            curSize++;
            front = (((front-1) % mxSize) + mxSize) % mxSize;
            arr[front] = value;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        curSize++;
        
        if(curSize == 1) front = 0;
        
        rear = (rear + 1) % mxSize;
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        curSize--;
        if(curSize == 0){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % mxSize;
        }
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        curSize--;
        if(curSize == 0){
            front = -1;
            rear = -1;
        }
        else{
            rear = (((rear-1) % mxSize) + mxSize) % mxSize;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(curSize == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(curSize == mxSize) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */