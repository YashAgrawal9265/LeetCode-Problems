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
        while(!st.empty() and st.top().first <= price){
            st.pop();
        }
        int result;
        if(!st.empty()){
            result = idx - st.top().second;
        }
        else{
            result = idx - (-1);
        }
        st.push({price,idx++});
        return result;
    }
};