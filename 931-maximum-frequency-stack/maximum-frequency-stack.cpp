class FreqStack {
public:
    unordered_map<int,int> mp;
    unordered_map<int,stack<int>> freqStack;
    int mxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        if(mp[val] > mxFreq){
            mxFreq = mp[val];
            freqStack[mxFreq] = stack<int>();
        }
        freqStack[mp[val]].push(val);
    }
    
    int pop() {
        int val = freqStack[mxFreq].top();
        freqStack[mxFreq].pop();
        if(freqStack[mxFreq].size() == 0) mxFreq--;
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */