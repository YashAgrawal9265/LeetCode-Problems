class MinStack {
private:
stack<long long> st;
long minEle;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        minEle = INT_MAX;
    }
    
    void push(int val) {
        long long new_ele;
        if(val < minEle){
            new_ele = 1LL*2*val - minEle;
            st.push(new_ele);
            minEle = val;
        }
        else{
            st.push(val);
        }
        
       
    }
    
    void pop() {
        if(st.size() == 0) return;
        if(st.top() < minEle){
            minEle = 1LL*2*(minEle) - st.top();
        }
        st.pop();
    } 
    
    int top() {
        if(st.size() == 0) return -1;
        if(st.top() < minEle) return minEle;
        return st.top();
    }
    
    int getMin() {
        return minEle;
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