class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2);
        next[0] = 0, next[1] = 0;
        for(int idx=n-1;idx>=0;idx--){
            vector<int> cur(2);
            for(int buy = 0; buy <=1; buy++){
                int profit = 0;
                if(buy){
                    int take = -prices[idx] + next[0];
                    int notake = next[1];
                    profit = max(take,notake);
                }
                else{
                    int take = prices[idx] + next[1];
                    int notake = next[0];
                    profit = max(take,notake);
                }
                cur[buy] = profit;
            }
            next = cur;
        }
        return next[1];
    }
};