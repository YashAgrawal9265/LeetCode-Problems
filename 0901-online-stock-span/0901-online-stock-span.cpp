class StockSpanner {
private:
    stack<pair<int,int>> st;
    int idx;
public:
    StockSpanner() {
        while(!st.empty()) st.pop();
        idx = 0;
    }
    
    int next(int price) {
        while(!st.empty() and price >= st.top().first) st.pop();
        int result;
        if(st.empty()) result = idx + 1;
        else result = idx - st.top().second;
        st.push({price,idx});
        idx++;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */