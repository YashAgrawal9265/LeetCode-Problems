class FreqStack {
unordered_map<int,int> mp;
unordered_map<int,stack<int>> stacks;
int mxFreq;
public:
    FreqStack() {
        mp.clear();
        stacks.clear();
        mxFreq = 0;
    }
    
    void push(int val) {
        mp[val] += 1;
        int cnt = mp[val];
        if(cnt > mxFreq){
            mxFreq = cnt;
            stacks[mxFreq] = stack<int>();
        }
        stacks[cnt].push(val);
    }
    
    int pop() {
        int val = stacks[mxFreq].top();
        stacks[mxFreq].pop();
        if(stacks[mxFreq].empty()){
            mxFreq--;
        }
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