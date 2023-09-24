class MinStack {
private:
    stack<long> st;
    long minVal = 1e10;
public:
    MinStack() {
       while(!st.empty()) st.pop(); 
    }
    
    void push(int val) {
        if(val < minVal){
            long newVal = 1LL*2*val - minVal;
            st.push(newVal);
            minVal = val;
        }
        else{
            st.push(val);
        }
    }
    
    void pop() {
        if(st.top() < minVal){
            minVal = 1LL*2*minVal - st.top();
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.top() < minVal){
            return minVal;
        }
        else{
            return st.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */