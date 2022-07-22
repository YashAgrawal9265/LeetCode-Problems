class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> cur(n+1,0), next(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i > j) continue;
                if(i == j){
                    cur[j] = piles[i];
                    continue;
                }
                int op1 = piles[i] - next[j];
                int op2 = piles[j] - cur[j-1];
                cur[j] = max(op1,op2);
            }
            next = cur;
        }
        int aliceScore = next[n-1];
        return aliceScore > 0;
    }
};