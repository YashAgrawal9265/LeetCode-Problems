class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        while(!q.empty()) q.pop(); 
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while(size > 1){
            q.push(q.front());
            q.pop();
            size--;
        }
        
    }
    
    int pop() {
        if(q.empty()) return -1;
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */