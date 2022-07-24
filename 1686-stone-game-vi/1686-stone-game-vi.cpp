class Solution {
public:
    int stoneGameVI(vector<int>& alice, vector<int>& bob) {
        int n = alice.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            int profit = alice[i] + bob[i];
            pq.push({profit,i});
        }
        int ascore = 0, bscore = 0;
        int turn = 0;
        while(!pq.empty()){
            if(turn == 0){
                ascore += alice[pq.top().second];
                pq.pop();
                turn = 1;
            }
            else{
                bscore += bob[pq.top().second];
                pq.pop();
                turn =0;
            }
        }
        if(ascore == bscore) return 0;
        return ascore > bscore ? 1 : -1;
    }
};