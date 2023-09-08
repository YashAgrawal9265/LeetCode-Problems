class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX, mxProfit = 0;
        for(int i=0;i<prices.size();i++){
            mxProfit = max(mxProfit,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return mxProfit;
    }
};