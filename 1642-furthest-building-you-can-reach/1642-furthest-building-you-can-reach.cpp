class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for(i=0;i<n-1;i++){
            if(heights[i] >= heights[i+1]) continue;
            int diff = heights[i+1]-heights[i];
            if(bricks >= diff){
                pq.push(diff);
                bricks -= diff;
            }
            else if(ladders > 0){
                if(!pq.empty() and diff < pq.top()){
                    bricks += (pq.top()-diff);
                    pq.pop();
                    pq.push(diff);
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};