class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i;
        for(i=0;i<n-1;i++){
            if(heights[i] >= heights[i+1]) continue;
            int diff = heights[i+1]-heights[i];
            if(diff <= bricks){
                bricks -= diff;
                pq.push(diff);
            }
            else{
                if(ladders == 0) break;
                if(!pq.empty() and pq.top() > diff){
                    int prev_bricks = pq.top();
                    pq.pop();
                    bricks += (prev_bricks - diff);
                    pq.push(diff);
                }
                ladders--;
            }
        }
        return i;
    }
};